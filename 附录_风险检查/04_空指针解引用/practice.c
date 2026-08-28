#include <stdio.h>
#include <stddef.h>

static int read_value(const int *pointer, int *result)
{
    if (/* TODO：任一指针为空 */) {
        return 0;
    }

    *result = *pointer;
    return 1;
}

int main(void)
{
    int value = 7;
    int result;

    printf("%d\n", read_value(&value, &result));
    printf("result = %d\n", result);
    return 0;
}

