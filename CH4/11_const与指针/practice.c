#include <stdio.h>

int main(void)
{
    int score = 95;
    int bonus = 5;

    /* TODO 1：声明一个“指向只读 int 的指针”，先指向 score。 */
    const int *read_only = /* 在这里填写 */;

    printf("read_only points to %d\n", *read_only);

    /* read_only 自己可以改指向，但不能通过它修改数据。 */
    read_only = &bonus;
    printf("read_only can point elsewhere: %d\n", *read_only);

    /* TODO 2：声明一个“不能改指向，但可以修改 int 数据”的指针。 */
    int *const fixed_pointer = /* 在这里填写 */;

    /* TODO 3：通过 fixed_pointer 把 score 增加 5。 */
    /* 在这里填写 */

    printf("fixed_pointer changed score to %d\n", score);

    /* 这个组合既不能改指向，也不能通过它修改数据。 */
    const int *const fixed_read_only = &score;

    printf("fixed_read_only reads %d\n", *fixed_read_only);

    return 0;
}

