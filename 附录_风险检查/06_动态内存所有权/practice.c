#include <stdio.h>
#include <stdlib.h>

static int *create_value(int value)
{
    int *result = /* TODO：申请一个 int */;
    if (result == NULL) {
        return NULL;
    }

    /* TODO：初始化 result */
    return result;
}

static void destroy_value(int **value)
{
    if (/* TODO：value 有效 */) {
        /* TODO：释放 *value 并置空 */
    }
}

int main(void)
{
    int *value = create_value(9);
    if (value == NULL) {
        return 1;
    }

    printf("%d\n", *value);
    destroy_value(&value);
    return 0;
}

