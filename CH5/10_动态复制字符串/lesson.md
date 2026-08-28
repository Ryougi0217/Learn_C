# 第 10 课：动态复制字符串

## 学习目标

手写一个返回堆上字符串副本的函数，理解字符串长度、结束符和所有权。

## 核心概念

- 字符串副本需要为所有字符和末尾的 `\0` 预留空间。
- `strlen` 不包含 `\0`，所以申请长度通常是 `strlen(text) + 1`。
- 复制完成后，返回的字符串由调用者负责 `free`。
- 输入参数用 `const char *` 表示函数不会修改原字符串。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *duplicate_string(const char *text)
{
    size_t length = strlen(text);
    char *copy = malloc((length + 1) * sizeof *copy);

    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, text, length + 1);
    return copy;
}

int main(void)
{
    char *copy = duplicate_string("heap string");

    if (copy == NULL) {
        return 1;
    }

    printf("%s\n", copy);
    free(copy);
    return 0;
}
```

## 练习任务

1. 完成 `duplicate_string` 的长度计算和空间申请。
2. 复制时把 `\0` 一起复制。
3. 在 `main` 中检查失败并释放副本。
4. 测试空字符串 `""`，确认仍然需要申请一个字节保存 `\0`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

