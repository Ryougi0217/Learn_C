#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    size_t bytes = sizeof values;
    size_t element_size = sizeof values[0];
    size_t count = bytes / element_size;

    printf("array bytes = %zu\n", bytes);
    printf("element bytes = %zu\n", element_size);
    printf("element count = %zu\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
    }

    return 0;
}

