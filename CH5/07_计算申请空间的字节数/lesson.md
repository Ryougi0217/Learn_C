# 第 7 课：计算申请空间的字节数

## 学习目标

用元素数量乘以单个元素大小计算动态数组空间，并避免手写类型大小。

## 核心概念

- 动态数组的字节数通常写成 `count * sizeof *pointer`。
- `sizeof *pointer` 表示一个元素的大小，不会解引用指针。
- 元素数量使用 `size_t` 表示更合适。
- 乘法可能发生整数溢出，复杂程序还要进行上限检查。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

static int *allocate_ints(size_t count)
{
    size_t bytes = count * sizeof(int);
    int *values = malloc(bytes);

    if (values == NULL && count != 0) {
        return NULL;
    }

    return values;
}

int main(void)
{
    size_t count = 3;
    int *values = allocate_ints(count);

    if (values == NULL) {
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        values[i] = (int)(i + 1);
        printf("%d\n", values[i]);
    }

    free(values);
    return 0;
}
```

## 练习任务

1. 完成 `allocate_ints` 中的字节数计算。
2. 把函数改成接收 `double` 数组，观察使用 `sizeof *values` 的好处。
3. 测试 `count == 0` 时的行为。
4. 思考当 `count` 非常大时，为什么乘法溢出会导致申请空间过小。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

