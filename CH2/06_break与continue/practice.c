#include <stdio.h>

int main(void)
{
    int stop_at = 8;

    for (int i = 1; i <= 10; i++) {
        if (i == stop_at) {
            break;
        }

        if (i % 2 == 0) {
            continue;
        }

        printf("接受：%d\n", i);
    }

    printf("循环结束。\n");
    return 0;
}

