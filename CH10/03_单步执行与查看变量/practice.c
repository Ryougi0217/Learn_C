#include <stdio.h>

static void add_points(int *score, int points)
{
    if (/* TODO：检查 score */) {
        /* TODO：通过指针增加 points */
    }
}

int main(void)
{
    int score = 70;

    add_points(&score, 5);
    printf("score = %d\n", score);
    return 0;
}

