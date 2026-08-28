# 第 17 课：空数据与单元素测试

## 学习目标

为算法补充空数组、单元素、重复值和已排序输入，避免只测试“正常长度”。

## 核心概念

- 空数据是最容易触发下标越界和除零的输入。
- 单元素数据可以暴露初始化和循环边界问题。
- 重复值可以检查查找和排序的稳定性约定。
- 测试应针对不变量，而不是只检查某一次打印。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

static int max_ints(const int values[], size_t count)
{
    if (count == 0) {
        return 0;
    }

    int maximum = values[0];
    for (size_t i = 1; i < count; i++) {
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }
    return maximum;
}

int main(void)
{
    int one[] = {42};

    printf("empty = %d\n", max_ints(NULL, 0));
    printf("single = %d\n", max_ints(one, 1));
    return 0;
}
```

## 练习任务

1. 为自己的查找和排序函数写空数组测试。
2. 测试单元素、全相等、逆序和极大/极小值。
3. 说明哪些函数允许 `values == NULL`，哪些函数只允许 count 为零。
4. 把每个测试用例写成“输入、预期、不变量、实际结果”。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

