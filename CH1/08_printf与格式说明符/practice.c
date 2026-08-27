#include <stdio.h>

int main(void)
{
    const char *name = "Ada";
    int score = 95;
    unsigned int level = 3u;
    double rate = 0.875;
    char grade = 'A';

    printf("name = %s\n", name);
    printf("score = %d\n", score);
    printf("level = %u\n", level);
    printf("rate = %.1f\n", rate);
    printf("grade = %c\n", grade);
    printf("progress = 100%%\n");

    printf("sizeof(score) = %zu\n", sizeof score);
    printf("sizeof(rate) = %zu\n", sizeof rate);

    return 0;
}

