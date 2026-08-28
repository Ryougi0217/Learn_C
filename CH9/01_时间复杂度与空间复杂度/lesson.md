# 第 1 课：时间复杂度与空间复杂度

## 学习目标

用输入规模描述算法成本，初步区分常数、线性、平方和对数级行为。

## 核心概念

- `O(1)` 的操作次数与输入规模无关。
- 单次遍历通常是 `O(n)`。
- 嵌套遍历常见为 `O(n²)`。
- 额外数组、节点和递归调用栈都会占用空间。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    int values[] = {4, 7, 2, 9};
    size_t count = sizeof values / sizeof values[0];

    puts("linear scan:");
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", values[i]);
    }

    puts("pair scan:");
    for (size_t i = 0; i < count; i++) {
        for (size_t j = i + 1; j < count; j++) {
            printf("(%d, %d)\n", values[i], values[j]);
        }
    }

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中标出两段循环的时间复杂度。
2. 把数组长度改为两倍，观察输出数量变化。
3. 找一个只使用固定数量变量的算法，说明其额外空间复杂度。
4. 解释为什么复杂度是增长趋势，不是某一次运行的精确秒数。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

