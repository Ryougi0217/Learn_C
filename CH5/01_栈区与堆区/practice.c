#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stack_value = 10;
    int *heap_value = /* TODO: 申请一个 int 的堆空间 */;

    if (heap_value == NULL) {
        fputs("heap allocation failed\n", stderr);
        return 1;
    }

    *heap_value = 20;

    printf("stack value = %d, address = %p\n",
           stack_value, (void *)&stack_value);
    printf("heap value = %d, address = %p\n",
           *heap_value, (void *)heap_value);

    /* TODO: 释放 heap_value，并考虑是否置为 NULL */

    return 0;
}

