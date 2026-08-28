# 第 11 课：综合项目 B——命令行通讯录

## 学习目标

使用固定容量结构体数组实现添加、查找和打印联系人，重点练习错误输入与接口拆分。

## 核心概念

- 每个联系人有姓名和电话号码字段。
- 添加前检查容量，查找时检查返回指针。
- 字符串复制必须考虑目标数组容量。
- 项目要区分用户输入错误和内部失败。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <string.h>

#define CONTACT_CAPACITY 4
#define NAME_CAPACITY 32
#define PHONE_CAPACITY 24

typedef struct
{
    char name[NAME_CAPACITY];
    char phone[PHONE_CAPACITY];
} Contact;

static int add_contact(Contact contacts[],
                       size_t *count,
                       const char *name,
                       const char *phone)
{
    if (*count >= CONTACT_CAPACITY
        || strlen(name) >= NAME_CAPACITY
        || strlen(phone) >= PHONE_CAPACITY) {
        return 0;
    }

    snprintf(contacts[*count].name, NAME_CAPACITY, "%s", name);
    snprintf(contacts[*count].phone, PHONE_CAPACITY, "%s", phone);
    (*count)++;
    return 1;
}

static const Contact *find_contact(const Contact contacts[],
                                  size_t count,
                                  const char *name)
{
    for (size_t i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

int main(void)
{
    Contact contacts[CONTACT_CAPACITY];
    size_t count = 0;

    add_contact(contacts, &count, "Ada", "10086");
    const Contact *contact = find_contact(contacts, count, "Ada");

    if (contact != NULL) {
        printf("%s %s\n", contact->name, contact->phone);
    }

    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中添加和查找函数。
2. 增加交互命令：add、find、list、quit。
3. 使用 `fgets` 读取命令，不要用不检查返回值的输入。
4. 测试名称过长、容量已满、查找不存在和空行。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

