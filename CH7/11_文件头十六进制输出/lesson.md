# 第 11 课：文件头十六进制输出

## 学习目标

读取文件开头的一小段字节，以十六进制形式输出，建立二进制初检能力。

## 核心概念

- 文件头常包含魔数、版本或格式标识。
- 十六进制输出能保留不可打印字节的信息。
- 只读初检只需要打开、读取和关闭，不应修改原文件。
- 输出长度必须受缓冲区容量限制。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int print_header(const char *path)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return 0;
    }

    unsigned char header[16];
    size_t count = fread(header, 1, sizeof header, file);

    if (ferror(file)) {
        fclose(file);
        return 0;
    }

    fclose(file);

    for (size_t i = 0; i < count; i++) {
        printf("%02X%s", header[i], i + 1 == count ? "" : " ");
    }
    putchar('\n');
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    return print_header(argv[1]) ? 0 : 1;
}
```

## 练习任务

1. 完成 `practice.c` 中的头部读取函数。
2. 测试空文件、短文件和超过 16 字节的文件。
3. 说明为什么输出函数不能假定一定读到 16 个字节。
4. 给每一行增加偏移量，例如 `00000000`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

