#include <stdio.h>
#include <stddef.h>

static int make_value(int *destination)
{
    if (/* TODO：检查 destination */) {
        return 0;
    }

    /* TODO：通过输出参数写入 42 */
    return 1;
}

int main(void)
{
    int result = 0;

    if (make_value(&result)) {
        printf("%d\n", result);
    }
    return 0;
}

