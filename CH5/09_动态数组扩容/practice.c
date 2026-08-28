#include <stdio.h>
#include <stdlib.h>

static int append_value(int **values,
                        size_t *count,
                        size_t *capacity,
                        int value)
{
    if (/* TODO: 容量已经用完 */) {
        size_t new_capacity = /* TODO: 计算新容量 */;
        int *grown = /* TODO: 用 realloc 扩容 */;

        if (/* TODO: 判断扩容失败 */) {
            return 0;
        }

        *values = grown;
        *capacity = new_capacity;
    }

    /* TODO: 把 value 写到数组末尾 */
    /* TODO: 增加 count */
    return 1;
}

int main(void)
{
    size_t count = 0;
    size_t capacity = 2;
    int *values = malloc(capacity * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    for (int value = 10; value <= 50; value += 10) {
        if (!append_value(&values, &count, &capacity, value)) {
            free(values);
            return 1;
        }
    }

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');

    free(values);
    return 0;
}

