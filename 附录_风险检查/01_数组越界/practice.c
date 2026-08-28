#include <stdio.h>

int main(void)
{
    int values[3] = {10, 20, 30};

#if defined(OOB_DEMO)
    /* TODO：把这一行改成越界访问，仅用于 ASan */
    printf("%d\n", values[2]);
#else
    /* TODO：填写最后一个合法下标 */
    printf("%d\n", values[2]);
#endif

    return 0;
}

