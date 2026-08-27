#include <stdio.h>

#define PASS_SCORE 60

int main(void)
{
    int score = 78;
    const int full_score = 100;
    int bonus = 5;

    bonus += 2;

    printf("score = %d/%d\n", score, full_score);
    printf("pass score = %d, bonus = %d\n", PASS_SCORE, bonus);

    return 0;
}

