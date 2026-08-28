# 第 2 课：线性查找

## 学习目标

从头到尾扫描数组，找到目标值第一次出现的位置。

## 核心概念

- 线性查找不要求数组有序。
- 最好情况是第一个元素匹配，最坏情况要检查全部元素。
- 找不到时用约定的结果表示，例如返回 `-1`。
- 函数参数需要同时接收数组和元素数量。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

static int linear_search(const int values[],
                         size_t count,
                         int target)
{
    for (size_t i = 0; i < count; i++) {
        if (values[i] == target) {
            return (int)i;
        }
    }

    return -1;
}

int main(void)
{
    int values[] = {8, 3, 8, 5};
    size_t count = sizeof values / sizeof values[0];

    printf("index = %d\n", linear_search(values, count, 5));
    printf("missing = %d\n", linear_search(values, count, 9));
    return 0;
}
```

## 练习任务

1. 手写 `linear_search`。
2. 测试目标在首位、末位、重复出现和不存在。
3. 测试空数组，确认函数不会访问 `values[0]`。
4. 解释为什么返回下标时要把找不到和合法下标区分开。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

