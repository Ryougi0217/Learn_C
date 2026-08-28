#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int score = 95;

    /*
     * TODO 1：先填写 NULL，运行空指针分支；
     * 再改成 &score，运行有效指针分支。
     */
    int *pointer = /* 在这里填写 */;

    if (pointer == NULL) {
        printf("pointer is empty\n");
    } else {
        printf("score through pointer = %d\n", *pointer);
    }

    return 0;
}

