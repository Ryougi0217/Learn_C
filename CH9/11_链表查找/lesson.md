# 第 11 课：链表查找

## 学习目标

遍历链表查找目标值，并返回节点指针或 `NULL`。

## 核心概念

- 查找不需要移动节点，只读取 next 链。
- 只读查找函数可以接收 `const Node *`。
- 返回节点指针时要说明它只是借用，不负责释放。
- 调用者使用返回值前要检查 `NULL`。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static const Node *find_node(const Node *head, int target)
{
    while (head != NULL) {
        if (head->value == target) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int main(void)
{
    Node third = {30, NULL};
    Node second = {20, &third};
    Node first = {10, &second};

    const Node *found = find_node(&first, 20);
    printf("%s\n", found == NULL ? "missing" : "found");
    return 0;
}
```

## 练习任务

1. 手写 `find_node`。
2. 测试首节点、尾节点、重复值和不存在。
3. 解释返回的节点为什么不能由查找函数释放。
4. 写一个可修改节点的非 const 查找版本。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

