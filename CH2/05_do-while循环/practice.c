#include <stdio.h>

int main(void)
{
    int limit = 3;
    int count = 0;

    do {
        count++;
        printf("这是第 %d 次执行\n", count);
    } while (count < limit);

    printf("最终次数：%d\n", count);
    return 0;
}

