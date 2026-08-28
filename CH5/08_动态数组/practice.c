#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t capacity = 4;
    size_t count = 0;
    int *values = /* TODO: 申请 capacity 个 int */;

    if (values == NULL) {
        return 1;
    }

    values[count++] = 12;
    values[count++] = 25;
    values[count++] = 38;

    for (size_t i = 0; i < count; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
    }

    /* TODO: 释放 values */

    return 0;
}

