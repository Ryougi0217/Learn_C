#include <stdio.h>
#include <stddef.h>

static void insertion_sort(int values[], size_t count)
{
    for (size_t i = 1; i < count; i++) {
        int current = values[i];
        size_t position = i;

        while (/* TODO：还有更大的左侧元素 */) {
            /* TODO：向右移动左侧元素 */
            /* TODO：位置向左移动 */
        }

        /* TODO：把 current 放入空出的位置 */
    }
}

int main(void)
{
    int values[] = {5, 2, 4, 6, 1, 3};
    size_t count = sizeof values / sizeof values[0];

    insertion_sort(values, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}

