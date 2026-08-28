#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t count;
    size_t capacity;
} IntVector;

static int vector_push(IntVector *vector, int value)
{
    if (/* TODO：容量已满 */) {
        size_t new_capacity = /* TODO：计算新容量 */;
        int *grown = /* TODO：安全 realloc */;

        if (/* TODO：扩容失败 */) {
            return 0;
        }

        vector->data = grown;
        vector->capacity = new_capacity;
    }

    /* TODO：保存 value 并递增 count */
    return 1;
}

static void vector_destroy(IntVector *vector)
{
    /* TODO：释放 data 并重置字段 */
}

int main(void)
{
    IntVector vector = {0};

    for (int i = 1; i <= 5; i++) {
        if (!vector_push(&vector, i * 10)) {
            vector_destroy(&vector);
            return 1;
        }
    }

    for (size_t i = 0; i < vector.count; i++) {
        printf("%d ", vector.data[i]);
    }
    putchar('\n');

    vector_destroy(&vector);
    return 0;
}

