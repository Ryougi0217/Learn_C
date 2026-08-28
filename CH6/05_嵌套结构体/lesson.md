# 第 5 课：嵌套结构体

## 学习目标

把一个结构体作为另一个结构体的成员，表示日期、坐标等有层次的数据。

## 核心概念

- 结构体成员可以是另一个结构体类型。
- 访问嵌套成员时连续使用点运算符。
- 通过结构体指针访问嵌套成员时可以连续使用箭头和点。
- 嵌套不等于继承，它只是把对象组合在一起。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Event
{
    const char *name;
    struct Date date;
};

int main(void)
{
    struct Event event = {
        "release",
        {2026, 8, 28}
    };

    printf("%s: %04d-%02d-%02d\n",
           event.name,
           event.date.year,
           event.date.month,
           event.date.day);

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中定义日期和事件结构体。
2. 补齐嵌套初始化。
3. 通过成员访问打印年月日。
4. 增加一个地点结构体，形成两层嵌套。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

