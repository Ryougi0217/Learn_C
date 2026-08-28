# 第 8 课：结构体作为函数参数

## 学习目标

比较按值传递结构体和传递结构体指针的接口差异。

## 核心概念

- 结构体按值传参会复制整个结构体。
- 只读查看时常用 `const struct Type *`，避免复制并表达不修改。
- 需要修改调用者对象时传入非 const 指针。
- 指针参数仍需检查是否为 `NULL`。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

struct Student
{
    const char *name;
    int score;
};

static void print_student(const struct Student *student)
{
    if (student == NULL) {
        return;
    }

    printf("%s: %d\n", student->name, student->score);
}

int main(void)
{
    struct Student student = {"A", 90};

    print_student(&student);
    return 0;
}
```

## 练习任务

1. 完成 `print_student` 的空指针检查和打印。
2. 在 `main` 中传入结构体地址。
3. 写一个 `raise_score` 函数，通过指针修改分数。
4. 解释为什么只读打印函数参数适合使用 `const`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

