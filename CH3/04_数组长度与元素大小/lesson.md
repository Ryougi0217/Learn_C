# 第 4 课：数组长度与元素大小

## 本课目标

完成本课后，你应该能够：

- 区分数组占用的总字节数和元素个数；
- 使用 `sizeof array` 得到数组对象大小；
- 使用 `sizeof array[0]` 得到单个元素大小；
- 通过两者相除计算数组元素数量。

## 1. `sizeof` 的两个问题

对数组来说，常见的两个问题是：

1. 整个数组占多少字节？
2. 数组中有多少个元素？

例如：

```c
int values[] = {10, 20, 30, 40};
size_t bytes = sizeof values;
size_t element_size = sizeof values[0];
size_t count = bytes / element_size;
```

`sizeof values` 是整个数组的大小，`sizeof values[0]` 是一个元素的大小。两者相除才是元素数量。

## 2. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    size_t bytes = sizeof values;
    size_t element_size = sizeof values[0];
    size_t count = bytes / element_size;

    printf("array bytes = %zu\n", bytes);
    printf("element bytes = %zu\n", element_size);
    printf("element count = %zu\n", count);

    return 0;
}
```

这里的结果表示当前编译器实现下的观察值。不同类型、平台或实现可能有不同的字节数。

## 3. 常见误区

不要把：

```
sizeof values
```

误认为元素数量。也不要用一个手写常数代替数组实际长度，否则修改数组后循环可能失效。

本课只讨论数组仍在当前作用域中的情况。数组作为函数参数传递后会涉及指针，后续章节再专门区分 `sizeof(array)` 和 `sizeof(pointer)`。

## 修改/观察任务

1. 修改数组元素数量，观察三个 `sizeof` 结果；
2. 换成 `double`、`char` 或 `long long` 数组；
3. 使用 `count` 遍历数组；
4. 记录“总字节数、单元素字节数、元素数量”三者关系；
5. 尝试把数组传给函数，并记录为什么后续要学习指针。

## 自测题

1. `sizeof array` 和 `sizeof array[0]` 分别表示什么？
2. 为什么两个大小相除可以得到元素数量？
3. 为什么不应该手写数组长度常数？
4. 数组类型变化时，哪个 `sizeof` 表达式会自动适应？
5. 为什么数组作为函数参数后不能简单照搬本课公式？

## 验收标准

- [ ] 能计算数组总字节数；
- [ ] 能计算单个元素大小；
- [ ] 能计算元素数量；
- [ ] 能解释当前平台观察值和标准保证的区别。


