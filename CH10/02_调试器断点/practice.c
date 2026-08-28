#include <stdio.h>

int main(void)
{
    int total = 0;

    for (int i = 1; i <= 5; i++) {
        /* TODO：在调试器中观察这一行前后的状态 */
        total += i;
        printf("i=%d total=%d\n", i, total);
    }

    return 0;
}

