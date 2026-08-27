#include <limits.h>
#include <stdio.h>

int main(void)
{
    short score = 95;
    unsigned long population = 140000UL;
    long long distance = 1234567890123LL;

    printf("score = %hd\n", score);
    printf("population = %lu\n", population);
    printf("distance = %lld\n", distance);
    printf("int range = %d to %d\n", INT_MIN, INT_MAX);

    printf("sizeof(score) = %zu\n", sizeof score);
    printf("sizeof(long long) = %zu\n", sizeof(long long));

    return 0;
}

