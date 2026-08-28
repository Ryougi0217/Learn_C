#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int values[] = {4, 7, 2, 9};
    size_t count = sizeof values / sizeof values[0];

    puts("linear scan:");
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", values[i]);
    }

    puts("pair scan:");
    for (size_t i = 0; i < count; i++) {
        for (size_t j = i + 1; j < count; j++) {
            printf("(%d, %d)\n", values[i], values[j]);
        }
    }

    return 0;
}

