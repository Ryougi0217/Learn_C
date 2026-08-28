#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *values = malloc(2 * sizeof *values);
    if (values == NULL) {
        return 1;
    }

    values[0] = 10;
    values[1] = 20;

    int *grown = /* TODO：用临时指针调用 realloc */;
    if (/* TODO：判断扩容失败 */) {
        free(values);
        return 1;
    }

    values = grown;
    values[2] = 30;
    values[3] = 40;

    printf("%d %d\n", values[0], values[3]);
    free(values);
    return 0;
}

