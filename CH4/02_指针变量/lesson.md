# 第 2 课：指针变量

## 本课目标

完成本课后，你应该能够：

- 声明一个指向特定类型的指针；
- 让指针保存某个对象的地址；
- 使用 `*` 读取指针指向的值；
- 区分指针变量本身和它指向的对象。

## 1. 指针的类型

`int *pointer` 表示 `pointer` 是一个指向 `int` 的指针：

```c
int score = 95;
int *pointer = &score;
```

这里：

- `score` 是一个 `int` 对象；
- `&score` 是它的地址；
- `pointer` 保存这个地址；
- `*pointer` 表示沿着地址找到 `score` 的值。

指针类型告诉编译器如何解释指针指向的内存，以及解引用时读取多少字节。

## 2. 观察指针和值

```c
printf("pointer address = %p\n", (void *) pointer);
printf("pointed value = %d\n", *pointer);
```

`pointer` 和 `*pointer` 不是同一个东西：前者是地址值，后者是地址处的 `int` 值。

## 3. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int score = 95;
    int *pointer = &score;

    printf("score = %d\n", score);
    printf("pointer address = %p\n", (void *) pointer);
    printf("score address = %p\n", (void *) &score);
    printf("pointed value = %d\n", *pointer);

    return 0;
}
```

两个地址输出应该指向同一个对象，但不要比较它们的具体文字形式。

## 常见错误

- 声明了未初始化的指针就解引用；
- 把普通整数当成地址使用；
- 使用错误的指针类型解释对象；
- 忘记 `*`，打印了地址而不是指向的值；
- 把 `pointer` 和 `*pointer` 的修改混为一谈。

## 挖空任务

1. 完成指针初始化表达式；
2. 比较 `pointer` 和 `&score` 的输出；
3. 比较 `score` 和 `*pointer` 的输出；
4. 增加一个指针，观察它指向另一个变量时发生什么；
5. 在解引用前说明指针当前指向哪个有效对象。

## 自测题

1. `int *pointer` 中的 `*` 表示什么？
2. `pointer` 和 `*pointer` 分别是什么？
3. 为什么未初始化指针不能直接解引用？
4. 指针类型为什么重要？
5. `pointer = &score` 改变的是谁？

## 验收标准

- [ ] 能声明并初始化指针；
- [ ] 能打印指针地址和指向的值；
- [ ] 能说明指针变量与目标对象的区别；
- [ ] 能指出未初始化指针的风险。

