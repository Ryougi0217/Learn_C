#include <stdio.h>

#define STACK_CAPACITY 4

typedef struct
{
    int values[STACK_CAPACITY];
    size_t top;
} Stack;

static int push(Stack *stack, int value)
{
    if (/* TODO：栈已满 */) {
        return 0;
    }

    /* TODO：写入并更新 top */
    return 1;
}

static int pop(Stack *stack, int *value)
{
    if (/* TODO：栈为空或输出指针为空 */) {
        return 0;
    }

    /* TODO：先移动 top，再取出栈顶 */
    return 1;
}

int main(void)
{
    Stack stack = {0};
    int value;

    push(&stack, 10);
    push(&stack, 20);

    while (pop(&stack, &value)) {
        printf("%d ", value);
    }
    putchar('\n');
    return 0;
}

