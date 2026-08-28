#include <limits.h>
#include <stdio.h>

static int add_checked(int left, int right, int *result)
{
    if (/* TODO：正数加法上溢 */) {
        return 0;
    }
    if (/* TODO：负数加法下溢 */) {
        return 0;
    }

    *result = left + right;
    return 1;
}

int main(void)
{
    int result;

    printf("%d\n", add_checked(INT_MAX, 1, &result));
    printf("%d\n", add_checked(10, 20, &result));
    return 0;
}

