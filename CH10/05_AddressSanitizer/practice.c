#include <stdio.h>

int main(void)
{
    int values[3] = {10, 20, 30};

#if defined(ASAN_DEMO)
    /* TODO：故意制造一次越界读取，仅用于 ASan */
    printf("%d\n", values[2]);
#else
    printf("%d\n", values[2]);
#endif

    return 0;
}

