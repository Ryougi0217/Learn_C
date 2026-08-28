# 第 18 课：数据结构所有权与销毁函数

## 学习目标

为拥有堆节点的数据结构设计明确的创建、借用、删除和销毁接口。

## 核心概念

- 拥有节点的链表必须提供统一销毁函数。
- 只读遍历函数不应释放节点。
- 删除节点时，数据所有权和节点所有权要分别说明。
- 销毁函数应能处理空头指针和部分构造成功的结构。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static int push_front(Node **head, int value)
{
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->next = *head;
    *head = node;
    return 1;
}

static void destroy_list(Node **head)
{
    if (head == NULL) {
        return;
    }

    while (*head != NULL) {
        Node *next = (*head)->next;
        free(*head);
        *head = next;
    }
}

int main(void)
{
    Node *head = NULL;

    push_front(&head, 1);
    push_front(&head, 2);
    destroy_list(&head);

    printf("head = %s\n", head == NULL ? "NULL" : "not NULL");
    return 0;
}
```

## 练习任务

1. 手写创建和销毁函数。
2. 让销毁函数在释放后把调用者头指针设为 `NULL`。
3. 测试空链表和创建中途失败。
4. 写一段注释说明谁拥有节点、谁只借用节点。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

