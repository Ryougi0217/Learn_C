# 第 4 课：结构体指针与 ->

## 学习目标

使用结构体指针访问成员，理解 `pointer->member` 是解引用后访问成员的简写。

## 核心概念

- 结构体指针使用 `->` 访问成员。
- `pointer->score` 等价于 `(*pointer).score`。
- 箭头左侧必须是结构体指针。
- 通过指针修改成员会修改调用者拥有的结构体。

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
    struct Student student = {"A", 80};
    struct Student *pointer = &student;

    pointer->score += 5;

    printf("%s: %d\n", pointer->name, pointer->score);
    printf("same score = %d\n", (*pointer).score);

    return 0;
}
```

## 练习任务

1. 让 `pointer` 指向 `student`。
2. 使用 `->` 把分数增加 `5`。
3. 把一条箭头表达式改写成点运算符和解引用。
4. 说明为什么 `student->score` 不是合法写法。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

