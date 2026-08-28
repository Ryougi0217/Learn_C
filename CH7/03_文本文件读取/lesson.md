# 第 3 课：文本文件读取

## 学习目标

使用 `fgets` 从文件中逐行读取文本，并正确处理 EOF 和错误。

## 核心概念

- `fgets(buffer, capacity, file)` 成功时返回缓冲区地址。
- 到达文件结尾或发生错误时可能返回 `NULL`。
- 读取行时要给字符数组预留容量。
- `feof` 不是提前判断读取成功的替代品，应该先检查读取函数返回值。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char line[128];
    size_t number = 0;

    while (fgets(line, sizeof line, file) != NULL) {
        number++;
        printf("%zu: %s", number, line);
    }

    if (ferror(file)) {
        perror("read");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的打开和 `fgets` 循环。
2. 用一个小文本文件测试空文件、单行和多行。
3. 处理读取结束后的 `ferror`。
4. 解释为什么不应只根据 `feof` 判断最后一次读取是否成功。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

