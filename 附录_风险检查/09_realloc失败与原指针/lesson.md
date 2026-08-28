# 附录第 9 课：realloc 失败与原指针

## 学习目标

在扩容失败时保留原指针，避免丢失内存地址和造成泄漏。

## 核心概念

- `realloc` 失败返回 `NULL`，原对象通常仍然有效。
- 临时指针接收结果是安全写法。
- 新字节数计算也要防止溢出。
- 失败路径应让调用者能够继续释放原数组。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *values = malloc(2 * sizeof *values);
    if (values == NULL) {
        return 1;
    }

    values[0] = 10;
    values[1] = 20;

    int *grown = realloc(values, 4 * sizeof *values);
    if (grown == NULL) {
        free(values);
        return 1;
    }

    values = grown;
    values[2] = 30;
    values[3] = 40;

    printf("%d %d\n", values[0], values[3]);
    free(values);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中完成临时指针扩容。
2. 故意使用直接赋值版本，说明它可能造成什么损失。
3. 为字节数乘法增加溢出检查。
4. 列出成功和失败两条路径的释放位置。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

