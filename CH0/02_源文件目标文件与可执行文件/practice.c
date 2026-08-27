#include <stdio.h>

static int square(int value)
{
    return value * value;
}

int main(void)
{
    int value = 7;

    printf("value = %d, square(value) = %d\n", value, square(value));
    return 0;
}

