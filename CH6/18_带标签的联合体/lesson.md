# 第 18 课：带标签的联合体

## 学习目标

把枚举标签和联合体数据组合起来，构造一个能够知道当前有效成员的安全接口。

## 核心概念

- 联合体本身不会记录当前存储的是哪个成员。
- 标签枚举负责说明当前有效的数据类型。
- 读取前先检查标签，再访问对应的联合体成员。
- 这是一种常见的 tagged union / discriminated union 设计。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

enum ValueKind
{
    VALUE_INT,
    VALUE_DOUBLE
};

union ValueData
{
    int integer;
    double decimal;
};

struct Value
{
    enum ValueKind kind;
    union ValueData data;
};

static void print_value(const struct Value *value)
{
    if (value == NULL) {
        return;
    }

    switch (value->kind) {
    case VALUE_INT:
        printf("int: %d\n", value->data.integer);
        break;
    case VALUE_DOUBLE:
        printf("double: %.2f\n", value->data.decimal);
        break;
    default:
        puts("unknown value");
        break;
    }
}

int main(void)
{
    struct Value first = {VALUE_INT, {.integer = 7}};
    struct Value second = {VALUE_DOUBLE, {.decimal = 2.5}};

    print_value(&first);
    print_value(&second);
    return 0;
}
```

## 练习任务

1. 完成标签枚举和联合体声明。
2. 在 `print_value` 中根据标签选择成员。
3. 增加字符串类型时，说明字符串指针的所有权由谁负责。
4. 构造一个未知标签，确认默认分支不会误读数据。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

