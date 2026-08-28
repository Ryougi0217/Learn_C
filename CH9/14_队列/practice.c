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
    if (/* TODO：队列已满 */) {
        return 0;
    }

    /* TODO：写入 tail 位置并让 tail 环回 */
    /* TODO：增加 count */
    return 1;
}

static int dequeue(Queue *queue, int *value)
{
    if (/* TODO：队列为空或输出指针为空 */) {
        return 0;
    }

    /* TODO：读取 head、让 head 环回并减少 count */
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

