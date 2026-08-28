# 第 7 课：类型别名 typedef

## 学习目标

使用 `typedef` 为结构体和其他类型提供更简洁、稳定的名字。

## 核心概念

- `typedef` 创建的是类型别名，不是新的运行时类型。
- 常见写法是给匿名结构体起一个名字。
- 别名应表达领域含义，不要只为了少写几个字符。
- 结构体标签和 typedef 名字可以同时存在。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

typedef enum
{
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE
} Color;

int main(void)
{
    Point point = {3, 4};
    Color color = COLOR_GREEN;

    printf("point = (%d, %d)\n", point.x, point.y);
    printf("color number = %d\n", color);

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中补齐 `Point` 的类型别名。
2. 定义一个 `typedef enum` 表示任务状态。
3. 使用别名声明变量，不再重复写 `struct`。
4. 解释 typedef 是别名而不是内存分配操作。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

