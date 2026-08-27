#include <stdio.h>

int main(void)
{
    int remaining = 3;

    while (remaining > 0) {
        printf("remaining = %d\n", remaining);
        remaining--;
    }

    printf("循环结束。\n");
    return 0;
}

