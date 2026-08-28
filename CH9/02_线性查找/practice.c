#include <stdio.h>
#include <stddef.h>

static int linear_search(const int values[],
                         size_t count,
                         int target)
{
    for (size_t i = 0; i < count; i++) {
        if (/* TODO：当前元素匹配 target */) {
            return /* TODO：返回下标 */;
        }
    }

    return /* TODO：表示找不到 */;
}

int main(void)
{
    int values[] = {8, 3, 8, 5};
    size_t count = sizeof values / sizeof values[0];

    printf("index = %d\n", linear_search(values, count, 5));
    printf("missing = %d\n", linear_search(values, count, 9));
    return 0;
}

