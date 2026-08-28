#include <stdio.h>

static unsigned long factorial_recursive(unsigned int n)
{
    if (/* TODO：基线条件 */) {
        return 1;
    }

    return /* TODO：缩小问题并递归 */;
}

static unsigned long factorial_iterative(unsigned int n)
{
    unsigned long result = 1;

    for (unsigned int i = 2; i <= n; i++) {
        /* TODO：累乘 */
    }

    return result;
}

int main(void)
{
    printf("recursive = %lu\n", factorial_recursive(5));
    printf("iterative = %lu\n", factorial_iterative(5));
    return 0;
}

