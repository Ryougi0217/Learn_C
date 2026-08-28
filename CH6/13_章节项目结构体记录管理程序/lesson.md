# 第 13 课：章节项目——结构体记录管理程序

## 学习目标

综合使用结构体数组、枚举、指针参数和函数拆分，完成一个小型记录管理程序。

## 核心概念

- 每条记录包含编号、名称、分数和状态。
- 添加函数通过指针修改记录数量。
- 查找函数返回记录指针；找不到时返回 `NULL`。
- 项目先使用固定容量数组，下一章动态内存再扩展容量。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

typedef enum
{
    RECORD_ACTIVE,
    RECORD_ARCHIVED
} RecordStatus;

typedef struct
{
    int id;
    const char *name;
    int score;
    RecordStatus status;
} Record;

static int add_record(Record records[],
                      size_t *count,
                      size_t capacity,
                      Record record)
{
    if (*count >= capacity) {
        return 0;
    }

    records[*count] = record;
    (*count)++;
    return 1;
}

static Record *find_record(Record records[],
                           size_t count,
                           int id)
{
    for (size_t i = 0; i < count; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }

    return NULL;
}

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
    Record records[4];
    size_t count = 0;

    add_record(records, &count, 4,
               (Record){1, "Ada", 98, RECORD_ACTIVE});
    add_record(records, &count, 4,
               (Record){2, "Lin", 87, RECORD_ACTIVE});

    print_record(find_record(records, count, 2));
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的添加函数。
2. 手写按编号查找函数。
3. 增加“修改分数”和“归档记录”操作。
4. 测试容量已满、查找不存在编号和分数边界。
5. 说明哪些函数只读，哪些函数会修改记录。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

