# 第 12 课：链表删除

## 学习目标

删除第一个匹配节点并重新连接前后节点，避免泄漏和悬空 next 指针。

## 核心概念

- 删除头节点时需要更新头指针。
- 删除中间节点时要让前一个节点跳过被删节点。
- 释放前先保存下一个需要保留的连接。
- 删除后不能继续使用已经释放的节点指针。

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

static int remove_first(Node **head, int target)
{
    Node **link = head;

    while (*link != NULL) {
        if ((*link)->value == target) {
            Node *removed = *link;
            *link = removed->next;
            free(removed);
            return 1;
        }
        link = &(*link)->next;
    }

    return 0;
}

int main(void)
{
    Node *first = malloc(sizeof *first);
    Node *second = malloc(sizeof *second);

    if (first == NULL || second == NULL) {
        free(first);
        free(second);
        return 1;
    }

    first->value = 10;
    first->next = second;
    second->value = 20;
    second->next = NULL;

    remove_first(&first, 10);
    printf("head = %d\n", first->value);

    free(first);
    return 0;
}
```

## 练习任务

1. 手写 `remove_first`。
2. 分别删除头、中间、尾部和不存在的值。
3. 画出 `Node **link` 在每轮循环中指向的位置。
4. 增加完整的链表销毁函数。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

