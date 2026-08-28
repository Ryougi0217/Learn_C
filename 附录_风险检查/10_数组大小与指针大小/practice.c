#include <stdio.h>

int main(void)
{
    int values[4] = {1, 2, 3, 4};
    int *pointer = values;

    printf("array bytes = %zu\n", /* TODO：数组整体大小 */);
    printf("element bytes = %zu\n", sizeof values[0]);
    printf("pointer bytes = %zu\n", sizeof pointer);
    return 0;
}

