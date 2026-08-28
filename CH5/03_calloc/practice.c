#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t count = 5;
    int *scores = calloc(/* TODO: 元素数量 */, /* TODO: 单个元素大小 */);

    if (scores == NULL) {
        fputs("calloc failed\n", stderr);
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        /* TODO: 先观察 calloc 的初始值，再决定是否写入 */
        printf("scores[%zu] = %d\n", i, scores[i]);
    }

    /* TODO: 释放 scores */

    return 0;
}

