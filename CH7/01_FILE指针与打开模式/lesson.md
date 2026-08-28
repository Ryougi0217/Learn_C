# 第 1 课：FILE * 与文件打开模式

## 学习目标

认识 `FILE *`，理解文本/二进制和读/写/追加模式的基本含义。

## 核心概念

- `FILE *` 是 C 标准库管理文件流的句柄。
- `"r"` 读取、`"w"` 覆盖写入、`"a"` 追加写入。
- 在二进制数据场景使用 `"rb"`、`"wb"` 等模式。
- 打开文件失败时返回 `NULL`，不能继续调用读写函数。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("sample.txt", "rb");

    if (file == NULL) {
        fputs("could not open sample.txt\n", stderr);
        return 1;
    }

    puts("file opened in binary read mode");
    fclose(file);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中填写文件名和打开模式。
2. 分别测试 `"r"`、`"rb"` 和 `"a"` 的含义。
3. 删除测试文件后运行，确认失败路径会执行。
4. 解释为什么打开模式是接口的一部分，而不是普通字符串装饰。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

