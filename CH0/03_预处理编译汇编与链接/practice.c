#include <stdio.h>

#define STARTING_SCORE 80

static int add_bonus(int score)
{
    return score >= 60 ? score + 5 : score;
}

int main(void)
{
    int final_score = add_bonus(STARTING_SCORE);

    printf("final score = %d\n", final_score);
    return 0;
}

