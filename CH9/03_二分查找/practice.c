#include <stdio.h>
#include <stddef.h>

static int binary_search(const int values[],
                         size_t count,
                         int target)
{
    size_t left = 0;
    size_t right = count;

    while (/* TODO：搜索区间非空 */) {
        size_t middle = left + (right - left) / 2;

        if (/* TODO：命中 */) {
            return /* TODO：返回中点下标 */;
        }
        if (/* TODO：中点值小于目标 */) {
            left = /* TODO：排除中点 */;
        } else {
            right = /* TODO：保留左半区间 */;
        }
    }

    return -1;
}

int main(void)
{
    int values[] = {2, 4, 7, 10, 13, 18};
    size_t count = sizeof values / sizeof values[0];

    printf("index = %d\n", binary_search(values, count, 10));
    return 0;
}

