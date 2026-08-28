# 第 3 课：二分查找

## 学习目标

在有序数组中不断缩小搜索区间，理解对数级查找。

## 核心概念

- 二分查找要求数组按目标方向有序。
- 使用半开区间 `[left, right)` 可以减少边界混乱。
- 中点可以写成 `left + (right - left) / 2`。
- 每轮必须让区间严格缩小，否则可能死循环。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

static int binary_search(const int values[],
                         size_t count,
                         int target)
{
    size_t left = 0;
    size_t right = count;

    while (left < right) {
        size_t middle = left + (right - left) / 2;

        if (values[middle] == target) {
            return (int)middle;
        }
        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return -1;
}

int main(void)
{
    int values[] = {2, 4, 7, 10, 13, 18};
    size_t count = sizeof values / sizeof values[0];

    printf("index = %d\n", binary_search(values, count, 10));
    printf("missing = %d\n", binary_search(values, count, 9));
    return 0;
}
```

## 练习任务

1. 手写半开区间版本的二分查找。
2. 测试空数组、单元素数组和两个元素数组。
3. 故意传入未排序数组，记录为什么结果不可靠。
4. 画出搜索目标为最小值、最大值和不存在时的区间变化。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

