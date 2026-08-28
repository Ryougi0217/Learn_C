# 第 10 课：综合项目 A——二进制文件分析器

## 学习目标

综合文件读取、文件大小、头部十六进制和基础签名识别，完成只读二进制分析器。

## 核心概念

- 工具只读打开目标文件，不修改输入。
- 文件大小、实际头部长度和签名判断必须分别检查。
- 输出应区分事实数据和推测格式。
- 项目错误路径要返回非零状态码。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <string.h>

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

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return 1;
    }
    long size = ftell(file);
    if (size < 0 || fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return 1;
    }

    unsigned char header[16];
    size_t count = fread(header, 1, sizeof header, file);
    if (ferror(file)) {
        fclose(file);
        return 1;
    }
    fclose(file);

    printf("size=%ld format=%s header_bytes=%zu\n",
           size, detect_format(header, count), count);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的文件大小和头部读取。
2. 加入 PNG、GIF 或 ZIP 签名。
3. 增加十六进制头部输出。
4. 用空文件、短文件、不存在文件和真实二进制文件测试。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

