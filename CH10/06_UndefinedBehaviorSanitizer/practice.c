#include <limits.h>
#include <stdio.h>

int main(void)
{
#if defined(UBSAN_DEMO)
    int value = INT_MAX;
    /* TODO：制造一次有符号溢出，仅用于 UBSan */
    printf("%d\n", value);
#else
    int value = INT_MAX;
    printf("%d\n", value);
#endif

    return 0;
}

