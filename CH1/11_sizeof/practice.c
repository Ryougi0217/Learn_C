#include <stdio.h>

int main(void)
{
    int scores[] = {88, 92, 76, 100};
    size_t element_count = sizeof scores / sizeof scores[0];

    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(scores) = %zu\n", sizeof scores);
    printf("sizeof(scores[0]) = %zu\n", sizeof scores[0]);
    printf("element count = %zu\n", element_count);

    return 0;
}

