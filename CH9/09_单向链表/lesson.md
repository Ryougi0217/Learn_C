# 第 9 课：单向链表

## 学习目标

认识节点、next 指针和从头到尾遍历的单向链表。

## 核心概念

- 每个节点保存数据和下一个节点地址。
- 最后一个节点的 `next` 是 `NULL`。
- 链表不要求节点连续存储。
- 遍历时要在解引用前确认节点指针非空。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stddef.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static void print_list(const Node *head)
{
    for (const Node *current = head;
         current != NULL;
         current = current->next) {
        printf("%d ", current->value);
    }
    putchar('\n');
}

int main(void)
{
    Node third = {30, NULL};
    Node second = {20, &third};
    Node first = {10, &second};

    print_list(&first);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中定义节点类型。
2. 手写链表遍历和打印。
3. 画出三个节点的 next 箭头。
4. 测试空链表，确认不会访问空指针。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

