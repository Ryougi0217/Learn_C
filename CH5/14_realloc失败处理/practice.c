#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int resize_values(int **values,
                          size_t old_count,
                          size_t new_count)
{
    (void)old_count;

    if (/* TODO: new_count 乘以元素大小会溢出 */) {
        return 0;
    }

    int *grown = /* TODO: 用临时指针调用 realloc */;

    if (/* TODO: grown 失败且 new_count 不为 0 */) {
        return 0;
    }

    /* TODO: 成功后让调用者指针指向 grown */
    return 1;
}

int main(void)
{
    size_t count = 2;
    int *values = malloc(count * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    values[0] = 10;
    values[1] = 20;

    if (!resize_values(&values, count, 4)) {
        free(values);
        return 1;
    }

    values[2] = 30;
    values[3] = 40;

    for (size_t i = 0; i < 4; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');

    free(values);
    return 0;
}

