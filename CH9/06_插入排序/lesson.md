# 第 6 课：插入排序

## 学习目标

把当前元素插入前面已经有序的区间，理解移动而不是反复交换。

## 核心概念

- 插入排序维护左侧有序区间。
- 当前值暂存在变量中，较大的元素向右移动。
- 对接近有序的数据，插入排序可能很快。
- 插入位置和循环停止条件是最容易出错的边界。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

static void insertion_sort(int values[], size_t count)
{
    for (size_t i = 1; i < count; i++) {
        int current = values[i];
        size_t position = i;

        while (position > 0
               && values[position - 1] > current) {
            values[position] = values[position - 1];
            position--;
        }

        values[position] = current;
    }
}

int main(void)
{
    int values[] = {5, 2, 4, 6, 1, 3};
    size_t count = sizeof values / sizeof values[0];

    insertion_sort(values, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写插入排序。
2. 在每次插入前打印当前有序区间。
3. 测试重复值，观察是否保持相同值的相对顺序。
4. 解释为什么 `position > 0` 必须出现在访问 `position - 1` 之前。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

