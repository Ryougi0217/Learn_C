#include <stdio.h>

int main(void)
{
    int score = 95;

    /* TODO 1：让 pointer 保存 score 的地址。 */
    int *pointer = /* 在这里填写 */;

    printf("score = %d\n", score);
    printf("pointer address = %p\n", (void *) pointer);
    printf("score address = %p\n", (void *) &score);
    printf("pointed value = %d\n", *pointer);

    return 0;
}

