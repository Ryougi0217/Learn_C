#include <stdio.h>
#include <stdlib.h>

static int *make_int(int value)
{
    /* TODO 1：申请一个 int */
    int *result = /* 在这里填写 */;

    if (/* TODO 2：判断申请失败 */) {
        return NULL;
    }

    /* TODO 3：初始化 result */
    return result;
}

int main(void)
{
    int *number = make_int(42);

    if (number == NULL) {
        fputs("could not create number\n", stderr);
        return 1;
    }

    printf("number = %d\n", *number);

    /* TODO 4：释放 number */

    return 0;
}

