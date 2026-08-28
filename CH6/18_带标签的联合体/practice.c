#include <stdio.h>

enum ValueKind
{
    /* TODO：声明 VALUE_INT 和 VALUE_DOUBLE */
};

union ValueData
{
    /* TODO：声明 integer 和 decimal */
};

struct Value
{
    enum ValueKind kind;
    union ValueData data;
};

static void print_value(const struct Value *value)
{
    if (value == NULL) {
        return;
    }

    switch (value->kind) {
    /* TODO：根据标签打印对应成员 */
    default:
        puts("unknown value");
        break;
    }
}

int main(void)
{
    struct Value first = {
        /* TODO：设置整数标签和数据 */
    };
    struct Value second = {
        /* TODO：设置浮点标签和数据 */
    };

    print_value(&first);
    print_value(&second);
    return 0;
}

