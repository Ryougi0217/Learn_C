# 第 12 课：数据结构命名与类型设计

## 学习目标

根据领域含义设计结构体、枚举和 typedef，使数据模型容易阅读和扩展。

## 核心概念

- 字段名应该表达业务含义，而不是只表达存储类型。
- 相关状态可以使用枚举集中定义。
- 类型别名让接口声明更简洁，但不能隐藏重要语义。
- 设计时先确定不变量，例如编号唯一、分数范围和名称容量。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

typedef enum
{
    RECORD_ACTIVE,
    RECORD_ARCHIVED
} RecordStatus;

typedef struct
{
    int id;
    char name[32];
    int score;
    RecordStatus status;
} Record;

static void print_record(const Record *record)
{
    if (record == NULL) {
        return;
    }

    printf("#%d %s score=%d status=%d\n",
           record->id, record->name,
           record->score, record->status);
}

int main(void)
{
    Record record = {1, "Ada", 98, RECORD_ACTIVE};

    print_record(&record);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中设计一个包含编号、名称、分数和状态的记录类型。
2. 让名称容量明确写在类型定义中。
3. 写一个函数检查编号为正、分数在 `0～100`。
4. 说明为什么把状态写成枚举比写成任意整数更好。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

