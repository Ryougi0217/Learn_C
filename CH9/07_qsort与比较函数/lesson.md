# 第 7 课：qsort 与比较函数

## 学习目标

使用标准库 `qsort` 排序，并实现符合接口要求的比较函数。

## 核心概念

- `qsort` 接收数组地址、元素数量、元素大小和比较函数。
- 比较函数返回负数、零或正数表示小于、相等或大于。
- 不要直接做 `left - right`，整数溢出会导致错误比较。
- `void *` 让库函数支持不同元素类型。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

static int compare_ints(const void *left,
                        const void *right)
{
    int first = *(const int *)left;
    int second = *(const int *)right;

    return (first > second) - (first < second);
}

int main(void)
{
    int values[] = {5, 2, 9, 1, 5};
    size_t count = sizeof values / sizeof values[0];

    qsort(values, count, sizeof values[0], compare_ints);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写 `compare_ints`，不要使用可能溢出的减法。
2. 补齐 `qsort` 的四个参数。
3. 为结构体数组写按分数比较的函数。
4. 解释比较函数为什么接收 `const void *`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

