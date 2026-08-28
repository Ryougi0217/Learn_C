#include <stdio.h>
#include <stddef.h>

static void bubble_sort(int values[], size_t count)
{
    for (size_t end = count; end > 1; end--) {
        int swapped = 0;

        for (size_t i = 1; i < end; i++) {
            if (/* TODO：左元素大于右元素 */) {
                /* TODO：交换两个元素 */
                swapped = 1;
            }
        }

        if (/* TODO：本轮没有交换 */) {
            break;
        }
    }
}

int main(void)
{
    int values[] = {5, 1, 4, 2, 8};
    size_t count = sizeof values / sizeof values[0];

    bubble_sort(values, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}

