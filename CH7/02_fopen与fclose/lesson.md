# 第 2 课：fopen 与 fclose

## 学习目标

正确打开和关闭文件，建立每个成功打开都必须对应关闭的习惯。

## 核心概念

- `fopen` 成功返回流指针，失败返回 `NULL`。
- `fclose` 返回 `0` 表示成功，非零表示关闭时发生错误。
- 写模式可能覆盖已有文件，练习前要确认目标路径。
- 文件关闭前，库可能仍有缓冲数据没有写到设备。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("example.txt", "w");

    if (file == NULL) {
        fputs("open for writing failed\n", stderr);
        return 1;
    }

    fputs("first line\n", file);

    if (fclose(file) != 0) {
        fputs("close failed\n", stderr);
        return 1;
    }

    puts("file written and closed");
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的 `fopen` 调用。
2. 写入一行后检查 `fclose` 返回值。
3. 把模式改成 `"a"`，观察再次运行是否覆盖原内容。
4. 说明为什么不能对同一个成功关闭的流重复调用 `fclose`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

