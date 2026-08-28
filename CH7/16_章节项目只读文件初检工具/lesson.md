# 第 16 课：章节项目——只读文件初检工具

## 学习目标

综合完成一个只读初检工具：输出文件大小、头部十六进制、签名猜测和 FNV-1a 校验值。

## 核心概念

- 项目只读打开目标文件，不创建、不修改、不删除文件。
- 每个分析步骤都检查失败返回值。
- 头部输出、签名判断和哈希计算都按实际读取字节数工作。
- 输出是初检结果，不替代完整解析器或安全鉴定。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static long file_size(FILE *file)
{
    if (fseek(file, 0, SEEK_END) != 0) {
        return -1;
    }

    long size = ftell(file);
    if (size < 0 || fseek(file, 0, SEEK_SET) != 0) {
        return -1;
    }

    return size;
}

static const char *detect_format(const unsigned char *header,
                                 size_t count)
{
    if (count >= 4 && memcmp(header, "%PDF", 4) == 0) {
        return "PDF";
    }
    if (count >= 4
        && header[0] == 0x7F
        && header[1] == 'E'
        && header[2] == 'L'
        && header[3] == 'F') {
        return "ELF";
    }
    return "unknown";
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    long size = file_size(file);
    if (size < 0) {
        fclose(file);
        return 1;
    }

    unsigned char header[16];
    size_t count = fread(header, 1, sizeof header, file);
    if (ferror(file)) {
        fclose(file);
        return 1;
    }

    printf("size = %ld\n", size);
    printf("format = %s\n", detect_format(header, count));
    printf("header =");
    for (size_t i = 0; i < count; i++) {
        printf(" %02X", header[i]);
    }
    putchar('\n');

    if (fclose(file) != 0) {
        return 1;
    }

    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的文件大小、头部读取和签名判断。
2. 加入 FNV-1a 分块哈希。
3. 测试空文件、短文件、文本文件和二进制文件。
4. 在 README 中写明工具只读、输出含义和已知局限。
5. 列出每个 `fopen` 的关闭位置。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

