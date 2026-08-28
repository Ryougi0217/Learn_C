#include <stdio.h>
#include <stddef.h>

static void selection_sort(int values[], size_t count)
{
    for (size_t start = 0; start < count; start++) {
        size_t minimum = start;

        for (size_t i = start + 1; i < count; i++) {
            if (/* TODO：发现更小元素 */) {
                minimum = i;
            }
        }

        /* TODO：把 values[minimum] 与 values[start] 交换 */
    }
}

int main(void)
{
    int values[] = {9, 3, 6, 1, 3};
    size_t count = sizeof values / sizeof values[0];

    selection_sort(values, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}

