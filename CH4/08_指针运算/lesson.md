# 第 8 课：指针运算

## 本课目标

完成本课后，你应该能够：

- 使用指针加减访问同一数组中的元素；
- 说明指针加 1 为什么不是地址数值简单加 1；
- 计算两个同一数组内指针之间的距离；
- 避免解引用越过数组最后一个元素。

## 1. 指针加法的步长

如果 `pointer` 是 `int *`，那么 `pointer + 1` 指向下一个 `int`，编译器会按 `sizeof(int)` 调整地址。若是 `double *`，步长则按 `sizeof(double)`。

```c
int values[] = {10, 20, 30, 40};
int *pointer = values;

printf("%d\n", *(pointer + 2));
```

这等价于读取 `values[2]`。

## 2. 合法范围

对于长度为 `count` 的数组，指针可以指向：

- 任意合法元素；
- 数组最后一个元素后面的一格（一位越界位置，只能比较或参与计算，不能解引用）。

不能把“指向末尾后一格”当成可以读取的元素。

## 3. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    size_t count = sizeof values / sizeof values[0];
    int *begin = values;
    int *end = values + count;
    int sum = 0;

    for (int *current = begin; current < end; current++) {
        sum += *current;
    }

    printf("sum = %d\n", sum);
    printf("distance = %td\n", end - begin);

    return 0;
}
```

`end - begin` 的结果是元素个数，而不是字节数。`%td` 用来输出 `ptrdiff_t` 类型的指针差值。

## 4. 不要跨数组运算

指针加法和减法只有在同一个数组对象（或一位越界位置）范围内才有明确意义。不能把一个数组的指针和另一个无关数组的指针随意相减。

## 挖空任务

1. 完成 `begin` 的初始化；
2. 完成 `end` 指向数组末尾后一格的表达式；
3. 写出循环中的指针递增和解引用；
4. 观察 `current < end` 为什么不能写成 `current <= end`；
5. 修改数组类型，比较指针步长和指针差值。

## 自测题

1. `pointer + 1` 实际前进多少字节？
2. 为什么指针运算需要知道指针类型？
3. 数组末尾后一格的指针能不能解引用？
4. `end - begin` 表示什么？
5. 两个不同数组的指针为什么不能随意相减？

## 验收标准

- [ ] 能用指针遍历数组；
- [ ] 能正确构造末尾后一格指针；
- [ ] 能使用指针差值计算元素数量；
- [ ] 能说明越界解引用的风险。

