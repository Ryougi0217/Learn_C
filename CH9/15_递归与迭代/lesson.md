# 第 15 课：递归与迭代

## 学习目标

用同一个问题比较递归和循环写法，理解递归的基线、递归步和调用栈。

## 核心概念

- 递归函数必须有能停止的基线条件。
- 每次递归调用都应让问题规模变小。
- 迭代通常使用显式循环和少量状态。
- 深递归会消耗调用栈，不能忽略空间成本。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static unsigned long factorial_recursive(unsigned int n)
{
    if (n <= 1) {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}

static unsigned long factorial_iterative(unsigned int n)
{
    unsigned long result = 1;

    for (unsigned int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main(void)
{
    printf("recursive = %lu\n", factorial_recursive(5));
    printf("iterative = %lu\n", factorial_iterative(5));
    return 0;
}
```

## 练习任务

1. 手写递归阶乘，明确基线条件。
2. 手写迭代阶乘并比较变量数量。
3. 输入较大的 `n`，观察整数溢出风险。
4. 解释递归版本的额外空间来自哪里。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

