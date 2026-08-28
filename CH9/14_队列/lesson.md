# 第 14 课：队列

## 学习目标

用环形数组实现先进先出队列，理解头尾下标和元素数量。

## 核心概念

- 队列从一端入队、另一端出队。
- 环形数组让下标到达末尾后回到零。
- 同时保存 `head`、`tail` 和 `count` 可以区分空和满。
- 入队前检查容量，出队前检查数量。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

#define QUEUE_CAPACITY 4

typedef struct
{
    int values[QUEUE_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
} Queue;

static int enqueue(Queue *queue, int value)
{
    if (queue->count == QUEUE_CAPACITY) {
        return 0;
    }

    queue->values[queue->tail] = value;
    queue->tail = (queue->tail + 1) % QUEUE_CAPACITY;
    queue->count++;
    return 1;
}

static int dequeue(Queue *queue, int *value)
{
    if (queue->count == 0 || value == NULL) {
        return 0;
    }

    *value = queue->values[queue->head];
    queue->head = (queue->head + 1) % QUEUE_CAPACITY;
    queue->count--;
    return 1;
}

int main(void)
{
    Queue queue = {0};
    int value;

    enqueue(&queue, 10);
    enqueue(&queue, 20);

    while (dequeue(&queue, &value)) {
        printf("%d ", value);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写 `enqueue` 和 `dequeue`。
2. 先出队再入队，测试环形下标回绕。
3. 测试队列满、空和输出指针为空。
4. 解释为什么只比较 `head == tail` 无法同时表示空和满。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

