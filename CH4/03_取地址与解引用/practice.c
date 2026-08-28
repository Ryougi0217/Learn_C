#include <stdio.h>

int main(void)
{
    int count = 3;

    /* TODO 1：让 pointer 指向 count。 */
    int *pointer = /* 在这里填写 */;

    printf("before = %d\n", count);

    /* TODO 2：通过 pointer 把 count 增加 2。 */
    /* 在这里填写 */

    printf("after = %d\n", count);
    printf("through pointer = %d\n", *pointer);

    return 0;
}

