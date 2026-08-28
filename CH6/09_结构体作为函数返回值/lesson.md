# 第 9 课：结构体作为函数返回值

## 学习目标

让函数按值返回一个结构体，理解返回的是结构体值而不是局部变量地址。

## 核心概念

- 结构体可以像整数一样作为函数返回值。
- 按值返回不会产生“返回局部变量地址”的悬空指针问题。
- 返回结构体适合表示小型、值语义对象。
- 大型对象的性能和所有权要结合实际接口设计。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

static Point make_point(int x, int y)
{
    Point point = {x, y};
    return point;
}

int main(void)
{
    Point point = make_point(3, 4);

    printf("(%d, %d)\n", point.x, point.y);
    return 0;
}
```

## 练习任务

1. 补齐 `make_point` 的局部结构体和返回语句。
2. 返回一个表示原点的 `Point`。
3. 解释这和返回 `&point` 的区别。
4. 增加一个计算两点距离平方的函数。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

