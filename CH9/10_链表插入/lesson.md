# 第 10 课：链表插入

## 学习目标

在链表头部或指定位置插入新节点，练习修改指针连接关系。

## 核心概念

- 头插可能改变头指针，因此函数常接收 `Node **`。
- 新节点先连接旧头，再更新头指针。
- 申请失败时原链表必须保持有效。
- 插入前要画出旧箭头和新箭头。

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

static void destroy_list(Node *head)
{
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    Node *head = NULL;

    push_front(&head, 20);
    push_front(&head, 10);

    for (Node *current = head;
         current != NULL;
         current = current->next) {
        printf("%d ", current->value);
    }
    putchar('\n');

    destroy_list(head);
    return 0;
}
```

## 练习任务

1. 手写 `push_front`。
2. 解释为什么参数是 `Node **` 而不是 `Node *`。
3. 测试空链表插入和申请失败路径。
4. 写一个在尾部插入的版本，比较需要保存哪些指针。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

