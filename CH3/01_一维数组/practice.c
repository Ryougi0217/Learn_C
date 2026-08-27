#include <stdio.h>

int main(void)
{
    int scores[] = {88, 92, 76, 100};
    size_t count = sizeof scores / sizeof scores[0];

    for (size_t i = 0; i < count; i++) {
        printf("scores[%zu] = %d\n", i, scores[i]);
    }

    return 0;
}

