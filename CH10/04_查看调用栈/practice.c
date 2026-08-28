#include <stdio.h>

static int level_three(int value)
{
    /* TODO：在调试器中观察 value */
    return value * 2;
}

static int level_two(int value)
{
    return /* TODO：调用 level_three */;
}

static int level_one(int value)
{
    return /* TODO：调用 level_two */;
}

int main(void)
{
    printf("result = %d\n", level_one(3));
    return 0;
}

