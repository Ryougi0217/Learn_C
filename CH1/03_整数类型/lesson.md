# 第 3 课：整数类型

## 本课目标

完成本课后，你应该能够：

- 选择合适的整数类型保存不同规模的整数；
- 使用 `<limits.h>` 查看实现提供的范围；
- 正确使用常见的整数格式说明符；
- 不把某台机器上的字节数当成所有平台的永恒保证。

## 1. 常见整数类型

常见类型包括：

| 类型 | 典型用途 |
| --- | --- |
| `signed char` / `unsigned char` | 很小的整数或字节相关数据 |
| `short` | 需要比 `int` 更小范围时 |
| `int` | 一般整数计算 |
| `long` | 需要更大范围，具体大小与平台有关 |
| `long long` | 至少提供较大的整数范围 |
| `size_t` | 表示对象大小和下标，常由 `sizeof` 产生 |

除 `char` 的大小定义为 1 个字节外，各类型的具体字节数和范围与实现有关。应使用 `<limits.h>` 中的宏了解当前编译器提供的范围，例如 `INT_MIN`、`INT_MAX`、`LLONG_MAX`。

## 2. 格式说明符

本课先掌握这些常见写法：

| 表达式类型 | `printf` 常用格式 |
| --- | --- |
| `int` | `%d` |
| `long` | `%ld` |
| `long long` | `%lld` |
| `size_t` | `%zu` |

格式说明符必须与传给 `printf` 的参数类型匹配，否则可能产生警告，甚至导致未定义行为。

## 3. 不要只看字节数

`sizeof(int)` 能告诉你当前实现中 `int` 占多少个字节，但不能单独告诉你所有平台的 `int` 范围。需要范围时看标准库宏，需要固定宽度整数时再学习固定宽度整数类型。

## 4. 完整示例

下面的示例可以直接编译。注意变量类型、常量后缀和每个 `printf` 格式说明符之间是一一对应的关系：

```c
#include <limits.h>
#include <stdio.h>

int main(void)
{
    short score = 95;
    unsigned long population = 140000UL;
    long long distance = 1234567890123LL;

    printf("score = %hd\n", score);
    printf("population = %lu\n", population);
    printf("distance = %lld\n", distance);
    printf("int range = %d to %d\n", INT_MIN, INT_MAX);
    printf("sizeof(score) = %zu\n", sizeof score);

    return 0;
}
```

## 修改/观察任务

1. 修改练习中的整数值，观察不同类型的输出；
2. 补充或调整格式说明符；
3. 输出 `INT_MIN`、`INT_MAX` 和 `sizeof` 结果；
4. 记录你机器上几种类型的字节数，并注明“这是当前实现的观察结果”。

## 自测题

1. 为什么不能只根据 `sizeof(int)` 推断所有平台的 `int` 范围？
2. `size_t` 常用来表示什么？
3. 为什么 `long long` 的格式不是 `%d`？
4. 编译器警告格式不匹配时，应该如何处理？
5. 什么时候需要查看 `<limits.h>`？

## 验收标准

- [ ] 能使用至少三种整数类型；
- [ ] 能正确打印 `int`、`long long` 和 `size_t`；
- [ ] 能使用范围宏而不是手写猜测的最大值；
- [ ] 能解释“当前平台观察值”和“标准保证”之间的区别。
```


