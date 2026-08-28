#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *score = /* TODO: 使用 malloc 申请一个 int */;

    if (/* TODO: 判断申请是否失败 */) {
        fputs("malloc failed\n", stderr);
        return 1;
    }

    /* TODO: 给堆上的整数写入 95 */
    printf("score = %d\n", *score);

    /* TODO: 释放 score */

    return 0;
}

