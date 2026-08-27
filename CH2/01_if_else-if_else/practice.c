#include <stdio.h>

int main(void)
{
    int score = 85;

    if (score < 0 || score > 100) {
        printf("分数超出范围。\n");
    } else if (score >= 90) {
        printf("等级：A\n");
    } else if (score >= 60) {
        printf("等级：通过\n");
    } else {
        printf("等级：需要继续练习\n");
    }

    return 0;
}

