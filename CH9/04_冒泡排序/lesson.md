# 第 4 课：冒泡排序

## 学习目标

通过相邻元素交换，把较大的元素逐步移动到数组末尾。

## 核心概念

- 每一轮把当前未排序区间的最大值冒泡到末尾。
- 交换次数和比较次数通常是平方级。
- 如果一轮没有交换，可以提前结束。
- 排序函数通过指针修改调用者数组。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

static void bubble_sort(int values[], size_t count)
{
    for (size_t end = count; end > 1; end--) {
        int swapped = 0;

        for (size_t i = 1; i < end; i++) {
            if (values[i - 1] > values[i]) {
                int temporary = values[i - 1];
                values[i - 1] = values[i];
                values[i] = temporary;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main(void)
{
    int values[] = {5, 1, 4, 2, 8};
    size_t count = sizeof values / sizeof values[0];

    bubble_sort(values, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写冒泡排序。
2. 增加交换标志，已排序数组时提前结束。
3. 测试逆序、重复值、空数组和单元素数组。
4. 解释为什么内层循环的右边界会逐轮缩小。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

