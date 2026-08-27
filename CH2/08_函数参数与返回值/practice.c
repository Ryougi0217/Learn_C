#include <stdio.h>

int add(int left, int right)
{
    /* TODO 1：返回两个参数的和。 */
    return /* 在这里填写 */;
}

int is_even(int value)
{
    /* TODO 2：返回 value 是否为偶数。 */
    return /* 在这里填写 */;
}

int main(void)
{
    int first = 7;
    int second = 4;

    /*
     * TODO 3：把 second 作为 add 的第二个实参。
     * 函数返回值保存在 total 中。
     */
    int total = add(first, /* 在这里填写 */);

    printf("%d + %d = %d\n", first, second, total);
    printf("%d 是否为偶数：%s\n",
           total,
           is_even(total) ? "是" : "否");

    return 0;
}

