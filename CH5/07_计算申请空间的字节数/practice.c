#include <stdio.h>
#include <stdlib.h>

static int *allocate_ints(size_t count)
{
    size_t bytes = /* TODO: count 个 int 需要的字节数 */;
    int *values = /* TODO: 申请 bytes 个字节 */;

    if (values == NULL && count != 0) {
        return NULL;
    }

    return values;
}

int main(void)
{
    size_t count = 3;
    int *values = allocate_ints(count);

    if (values == NULL) {
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        values[i] = (int)(i + 1);
        printf("%d\n", values[i]);
    }

    /* TODO: 释放 values */

    return 0;
}

