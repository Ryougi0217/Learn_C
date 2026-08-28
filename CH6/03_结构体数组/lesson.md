# 第 3 课：结构体数组

## 学习目标

创建结构体数组，并使用循环遍历记录、统计字段。

## 核心概念

- `struct Student students[3]` 表示三个连续的结构体元素。
- 数组下标先定位元素，再用点运算符访问成员。
- 结构体数组的长度仍然可以用 `sizeof array / sizeof array[0]` 计算。
- 统计时要明确使用哪个成员。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

struct Student
{
    const char *name;
    int score;
};

int main(void)
{
    struct Student students[] = {
        {"A", 80},
        {"B", 95},
        {"C", 72}
    };
    size_t count = sizeof students / sizeof students[0];
    int total = 0;

    for (size_t i = 0; i < count; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
        total += students[i].score;
    }

    printf("average = %.2f\n", (double)total / (double)count);
    return 0;
}
```

## 练习任务

1. 补齐 `practice.c` 中结构体数组的初始化。
2. 遍历并打印每条记录。
3. 计算最高分而不是只计算总分。
4. 测试数组只有一个元素时的结果。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

