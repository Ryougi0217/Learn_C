# 第 5 课：选择排序

## 学习目标

每轮从未排序区间选择最小元素，放到当前起始位置。

## 核心概念

- 选择排序每轮只需要决定一个最小值位置。
- 交换次数较少，但比较次数仍通常是 `O(n²)`。
- 记录下标比复制整个元素更适合结构体等较大对象。
- 空数组和单元素数组应直接安全返回。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

static void selection_sort(int values[], size_t count)
{
    for (size_t start = 0; start < count; start++) {
        size_t minimum = start;

        for (size_t i = start + 1; i < count; i++) {
            if (values[i] < values[minimum]) {
                minimum = i;
            }
        }

        int temporary = values[start];
        values[start] = values[minimum];
        values[minimum] = temporary;
    }
}

int main(void)
{
    int values[] = {9, 3, 6, 1, 3};
    size_t count = sizeof values / sizeof values[0];

    selection_sort(values, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写选择排序并记录最小元素下标。
2. 优化当 `minimum == start` 时不进行交换。
3. 画出第一轮和最后一轮的未排序区间。
4. 比较选择排序和冒泡排序的交换次数。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

