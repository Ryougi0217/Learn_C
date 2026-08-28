# 第 12 课：sizeof(array) 与 sizeof(pointer)

## 学习目标

完成本课后，你应该能够：

1. 解释数组名和指针在表达式中的常见关系；
2. 区分数组整体大小和指针变量自身的大小；
3. 解释为什么数组传入函数后不能依靠 `sizeof` 推出元素数量；
4. 正确使用显式的元素个数参数。

## 1. 数组整体和指针变量不是一回事

看下面的代码：

```c
#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40, 50};
    int *pointer = values;

    printf("sizeof values = %zu\n", sizeof values);
    printf("sizeof pointer = %zu\n", sizeof pointer);

    return 0;
}
```

`values` 是一个包含 5 个 `int` 的数组：

```text
sizeof values = 5 * sizeof(int)
```

`pointer` 是一个指针变量：

```text
sizeof pointer = 指针变量自身占用的大小
```

指针大小由平台和 ABI 决定，不能把它当成数组元素数量。

在很多 64 位环境中，你可能看到：

```text
sizeof values = 20
sizeof pointer = 8
```

但不要把这些具体数字写死。正确的关系是：

```c
sizeof values == 5 * sizeof(int)
```

## 2. 数组名什么时候会转换成指针

在很多表达式中，数组名会转换成指向首元素的指针：

```c
int values[] = {10, 20, 30};
int *pointer = values;

printf("%d\n", values[0]);
printf("%d\n", pointer[0]);
```

但 `sizeof values` 是一个重要例外：这里需要的是整个数组类型的大小，所以不会先转换成指针。

同样，取地址 `&values` 得到的是“整个数组的地址”，它和 `values` 的类型也不同：

```c
int values[3];

int *first = values;
int (*whole_array)[3] = &values;
```

本课先掌握最常用的两个结论：

- `values` 常常可以作为首元素地址使用；
- `sizeof values` 在数组仍然是数组的作用域内，得到整个数组大小。

## 3. 数组作为函数参数时会发生什么

下面两种参数写法在函数声明中等价：

```c
static void inspect_a(const int values[], size_t count)
{
    /* ... */
}

static void inspect_b(const int *values, size_t count)
{
    /* ... */
}
```

函数参数中的数组记号会被调整为指针。因此函数内部的 `values` 实际上是一个指针参数。

这意味着函数不能仅靠：

```c
sizeof values
```

得到调用者数组的总大小。正确做法是把元素数量作为另一个参数传入：

```c
static void print_array(const int *values, size_t count)
{
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", values[i]);
    }
}
```

函数参数中的 `count` 是接口的一部分，调用者必须保证它与实际有效元素数量匹配。

## 4. 完整示例

```c
#include <stdio.h>
#include <stddef.h>

static void print_array_info(const int *values, size_t count)
{
    printf("inside function: sizeof values = %zu\n", sizeof values);
    printf("inside function: count = %zu\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
    }
}

int main(void)
{
    int values[] = {10, 20, 30, 40, 50};
    int *pointer = values;
    size_t count = sizeof values / sizeof values[0];

    printf("outside: sizeof values = %zu\n", sizeof values);
    printf("outside: sizeof pointer = %zu\n", sizeof pointer);
    printf("outside: count = %zu\n", count);

    print_array_info(values, count);

    return 0;
}
```

这里的 `count` 计算只适用于数组仍然是数组的作用域：

```c
size_t count = sizeof values / sizeof values[0];
```

进入 `print_array_info` 后，参数 `values` 已经是指针，所以应使用调用者传入的 `count`。

## 5. 练习任务

第 12 课的脚本是一个完整、可运行的对照实验。先运行它，再修改代码验证自己的预测：

### 任务 A：观察大小

记录以下三个表达式的结果：

- `sizeof values`；
- `sizeof values[0]`；
- `sizeof pointer`。

然后验证：

```c
sizeof values / sizeof values[0]
```

是否等于数组元素数量。

### 任务 B：修改数组

把数组改成 3 个元素，再观察：

- 数组整体大小是否变化；
- 指针自身大小是否变化；
- 函数收到的 `count` 是否变化。

### 任务 C：解释函数参数

回答：

1. 为什么 `print_array_info` 里不能用 `sizeof values / sizeof values[0]` 计算调用者数组长度？
2. 为什么必须显式传入 `count`？
3. 如果错误地传入比实际元素数量更大的 `count`，可能发生什么？

## 本课检查点

- [ ] 我能区分数组整体大小和指针变量大小。
- [ ] 我知道数组名在很多表达式中会转换成首元素指针。
- [ ] 我知道 `sizeof array` 是数组大小的例外场景。
- [ ] 我知道数组作为函数参数后需要额外传入长度。
- [ ] 我能写出安全遍历数组的“指针 + 元素个数”接口。

