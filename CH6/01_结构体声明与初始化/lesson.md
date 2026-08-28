# 第 1 课：结构体声明与初始化

## 学习目标

学习用结构体把多个相关字段组合成一个有名字的类型值。

## 核心概念

- `struct` 类型可以包含不同类型的成员。
- 声明结构体变量后，每个成员都有自己的存储空间。
- 初始化列表的顺序要和成员声明顺序对应。
- 结构体变量可以整体复制，但这里先关注声明和初始化。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

struct Student
{
    const char *name;
    int age;
    double score;
};

int main(void)
{
    struct Student student = {"Lin", 20, 91.5};

    printf("name = %s\n", student.name);
    printf("age = %d\n", student.age);
    printf("score = %.1f\n", student.score);

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中补齐结构体变量的初始化。
2. 增加一个整数编号成员并打印。
3. 初始化第二个学生，比较两个结构体变量。
4. 解释为什么结构体初始化顺序会影响结果。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

