#include <stdio.h>
#include <stddef.h>

static void print_array_info(const int *values, size_t count)
{
    printf("inside function: sizeof values = %zu\n", sizeof values);
    printf("inside function: count = %zu\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
    }
}

int main(void)
{
    int values[] = {10, 20, 30, 40, 50};
    int *pointer = values;
    size_t count = sizeof values / sizeof values[0];

    printf("outside: sizeof values = %zu\n", sizeof values);
    printf("outside: sizeof pointer = %zu\n", sizeof pointer);
    printf("outside: count = %zu\n", count);

    print_array_info(values, count);

    return 0;
}

