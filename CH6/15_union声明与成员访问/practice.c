#include <stdio.h>

union Number
{
    /* TODO：声明 integer 和 decimal */
};

int main(void)
{
    union Number value = /* TODO：用整数成员初始化 */;

    printf("integer = %d\n", value.integer);

    /* TODO：写入 3.5f 到 decimal */
    printf("decimal = %.1f\n", value.decimal);
    return 0;
}

