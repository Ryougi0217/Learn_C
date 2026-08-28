# 第 4 课：文本文件写入

## 学习目标

使用 `fputs`、`fputc` 和 `fprintf` 向文本文件写入可读内容。

## 核心概念

- `fputs` 写入字符串，`fputc` 写入单个字符。
- `fprintf` 可以把格式化结果写入文件流。
- 这些函数的返回值可以帮助发现写入失败。
- 关闭文件时也可能报告缓冲区写出错误。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("report.txt", "w");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    if (fprintf(file, "name=%s score=%d\n", "Ada", 98) < 0) {
        perror("fprintf");
        fclose(file);
        return 1;
    }

    if (fputs("status=pass\n", file) == EOF) {
        perror("fputs");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("fclose");
        return 1;
    }

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中补齐格式化写入。
2. 再写入一行状态和一个单独字符。
3. 检查写入函数与关闭函数的返回值。
4. 用文本编辑器打开生成文件，核对换行和内容。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

