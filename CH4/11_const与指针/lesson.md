# 第 11 课：const 与指针

## 学习目标

完成本课后，你应该能够区分：

- 指向只读数据的指针；
- 指针本身不能改指向的指针；
- 指针和它指向的数据都不能修改的组合。

本课第一次集中比较几种常见的 `const` 写法，所以练习脚本会保留关键挖空。

## 1. 指向常量数据的指针

```c
int score = 95;
const int *read_only = &score;
```

`read_only` 可以读取 `score`：

```c
printf("%d\n", *read_only);
```

但不能通过它修改 `score`：

```c
/* *read_only = 100; */  /* 编译器应拒绝 */
```

这里的含义是：

- `read_only` 自己可以改为指向另一个 `int`；
- `*read_only` 不能通过这个指针被修改；
- `const` 修饰的是指针所看到的数据。

因此下面的代码是允许的：

```c
int bonus = 10;

read_only = &bonus;
printf("%d\n", *read_only);
```

## 2. 指针本身是常量

```c
int score = 95;
int *const fixed_pointer = &score;
```

`fixed_pointer` 初始化后不能再指向别的变量：

```c
/* fixed_pointer = &bonus; */  /* 编译器应拒绝 */
```

但是可以通过它修改 `score`：

```c
*fixed_pointer = 100;
```

这里的 `const` 修饰的是指针变量本身。

## 3. 两者都不能修改

```c
int score = 95;
const int *const fixed_read_only = &score;
```

这个指针有两层限制：

- 不能让 `fixed_read_only` 改指向；
- 不能通过它修改 `score`。

它只适合在函数中表达“我只读取这块数据，而且不会改变指向关系”的意图。

## 4. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int score = 95;
    int bonus = 5;

    const int *read_only = &score;

    printf("read_only points to %d\n", *read_only);
    read_only = &bonus;
    printf("read_only can point elsewhere: %d\n", *read_only);

    int *const fixed_pointer = &score;

    *fixed_pointer += 5;
    printf("fixed_pointer changed score to %d\n", score);

    const int *const fixed_read_only = &score;

    printf("fixed_read_only reads %d\n", *fixed_read_only);

    return 0;
}
```

判断 `const` 修饰谁时，可以从变量名向左读：

- `const int *read_only`：`read_only` 是指针，指向 `const int`；
- `int *const fixed_pointer`：`fixed_pointer` 是常量指针，指向 `int`；
- `const int *const fixed_read_only`：两边的限制都存在。

## 5. 与函数参数结合

文本统计函数通常不需要修改输入字符串，因此可以写成：

```c
static int first_value(const int *values)
{
    return values[0];
}
```

`const int *` 告诉读代码的人：这个函数通过 `values` 读取数据，但不应该通过它修改元素。

如果函数确实需要修改调用者提供的数组，则不能把参数声明为指向常量数据的指针：

```c
static void set_first_value(int *values, int value)
{
    values[0] = value;
}
```

`const` 不只是语法要求，也是在接口中表达“谁拥有修改权限”。

## 6. 练习任务

打开 `practice.c`，完成关键声明和写入表达式。

### 任务 A：只读数据指针

让 `read_only` 指向 `score`，并保持：

- 可以打印 `*read_only`；
- 可以把它重新指向 `bonus`；
- 不能通过它修改整数。

### 任务 B：常量指针

让 `fixed_pointer` 指向 `score`，然后通过它把 `score` 增加 `5`。

要求理解：

- 不能给 `fixed_pointer` 重新赋值；
- 可以给 `*fixed_pointer` 赋值。

### 任务 C：自己写三种声明

不看答案，分别声明：

1. 可以改变指向，但不能修改数据的指针；
2. 不能改变指向，但可以修改数据的指针；
3. 两者都不能修改的指针。

### 任务 D：预测结果

回答：

1. `const int *p` 中，`const` 主要限制谁？
2. `int *const p` 中，`const` 主要限制谁？
3. 为什么统计函数常用 `const char *` 参数？
4. 如果把 `const int *` 改成 `int *`，调用者会多授予函数什么权限？

## 本课检查点

- [ ] 我能区分 `const int *` 和 `int *const`。
- [ ] 我手写过三种常见声明。
- [ ] 我知道只读指针仍然可以改指向。
- [ ] 我知道常量指针仍然可以修改指向的数据。
- [ ] 我能根据函数参数判断函数是否应该修改调用者数据。

