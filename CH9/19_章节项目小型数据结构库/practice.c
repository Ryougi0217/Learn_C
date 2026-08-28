#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t count;
    size_t capacity;
} IntVector;

static int vector_init(IntVector *vector)
{
    /* TODO：把三个字段初始化为安全空状态 */
    return 1;
}

static int vector_push(IntVector *vector, int value)
{
    if (/* TODO：容量已满 */) {
        size_t new_capacity = /* TODO：计算新容量 */;
        int *grown = /* TODO：安全扩容 */;

        if (/* TODO：判断失败 */) {
            return 0;
        }

        vector->data = grown;
        vector->capacity = new_capacity;
    }

    /* TODO：写入 value 并递增 count */
    return 1;
}

static int vector_get(const IntVector *vector,
                      size_t index,
                      int *result)
{
    if (/* TODO：检查下标和输出指针 */) {
        return 0;
    }

    *result = vector->data[index];
    return 1;
}

static void vector_destroy(IntVector *vector)
{
    /* TODO：释放并重置向量 */
}

int main(void)
{
    IntVector vector;
    vector_init(&vector);

    for (int i = 0; i < 5; i++) {
        if (!vector_push(&vector, i * i)) {
            vector_destroy(&vector);
            return 1;
        }
    }

    int value;
    if (vector_get(&vector, 3, &value)) {
        printf("value = %d\n", value);
    }

    vector_destroy(&vector);
    return 0;
}

