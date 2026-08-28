#include <stdio.h>
#include <stdlib.h>

static int *create_owned_value(int value)
{
    int *result = /* TODO: 申请一个 int */;

    if (result == NULL) {
        return NULL;
    }

    /* TODO: 初始化 result */
    return result;  /* 所有权交给调用者 */
}

static void destroy_owned_value(int **value)
{
    if (/* TODO: value 和 *value 都有效 */) {
        /* TODO: 释放 *value */
        /* TODO: 把 *value 置为 NULL */
    }
}

int main(void)
{
    int *value = create_owned_value(88);

    if (value == NULL) {
        return 1;
    }

    printf("%d\n", *value);
    destroy_owned_value(&value);

    return 0;
}

