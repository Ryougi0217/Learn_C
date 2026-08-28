#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t old_count = 2;
    size_t new_count = 4;
    int *values = malloc(old_count * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    values[0] = 10;
    values[1] = 20;

    /* TODO: 用临时指针接收 realloc 的结果 */
    int *grown = /* 在这里填写 */;

    if (grown == NULL) {
        /* TODO: 失败时释放仍然有效的 values */
        return 1;
    }

    values = grown;
    values[2] = 30;
    values[3] = 40;

    for (size_t i = 0; i < new_count; i++) {
        printf("%d\n", values[i]);
    }

    /* TODO: 释放 values */

    return 0;
}

