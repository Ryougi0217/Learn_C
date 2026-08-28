#include <stdio.h>

typedef struct
{
    int score;
} Result;

static void add_by_value(Result result)
{
    /* TODO：给副本增加 10 */
}

static void add_by_pointer(Result *result)
{
    if (/* TODO：检查指针 */) {
        /* TODO：给调用者对象增加 10 */
    }
}

int main(void)
{
    Result result = {70};

    add_by_value(result);
    printf("after value = %d\n", result.score);

    add_by_pointer(&result);
    printf("after pointer = %d\n", result.score);
    return 0;
}

