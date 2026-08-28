# 第 2 课：结构体成员访问

## 学习目标

使用点运算符访问和修改结构体成员，理解成员表达式的类型和值。

## 核心概念

- 普通结构体变量使用 `.` 访问成员。
- 每个成员可以像普通变量一样读取和赋值。
- 修改一个成员不会自动修改其他成员。
- 成员名只在对应结构体类型的上下文中有意义。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

struct Product
{
    const char *name;
    int stock;
    double price;
};

int main(void)
{
    struct Product product = {"keyboard", 3, 129.0};

    product.stock += 2;
    product.price = 119.0;

    printf("%s: stock=%d price=%.1f\n",
           product.name, product.stock, product.price);

    return 0;
}
```

## 练习任务

1. 用点运算符读取 `practice.c` 中的库存。
2. 把库存增加 `5`，把价格改成新的值。
3. 增加一个“是否上架”的整数成员。
4. 说明 `product.stock` 与 `stock` 为什么不是同一个名字。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

