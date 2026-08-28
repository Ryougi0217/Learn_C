#include <stdio.h>

int main(void)
{
    int score = 95;
    int replacement = 100;

    /* TODO 1：让 pointer 指向 score。 */
    int *pointer = /* 在这里填写 */;

    /* TODO 2：让 double_pointer 指向 pointer。 */
    int **double_pointer = /* 在这里填写 */;

    printf("before = %d\n", **double_pointer);

    /* TODO 3：通过 double_pointer 让 pointer 改指向 replacement。 */
    /* 在这里填写 */

    printf("after = %d\n", **double_pointer);
    printf("pointer now points to = %d\n", *pointer);

    return 0;
}

