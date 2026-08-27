#include <stdio.h>

int main(void)
{
    int n = 5;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("1 到 %d 的总和是 %d\n", n, sum);
    return 0;
}

