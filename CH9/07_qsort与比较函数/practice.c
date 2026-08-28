#include <stdio.h>
#include <stdlib.h>

static int compare_ints(const void *left,
                        const void *right)
{
    int first = *(const int *)left;
    int second = *(const int *)right;

    /* TODO：返回不溢出的三向比较结果 */
}

int main(void)
{
    int values[] = {5, 2, 9, 1, 5};
    size_t count = sizeof values / sizeof values[0];

    /* TODO：填写 qsort 的四个参数 */
    qsort(values, count, sizeof values[0], compare_ints);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');
    return 0;
}

