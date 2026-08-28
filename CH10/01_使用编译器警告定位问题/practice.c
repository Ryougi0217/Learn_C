#include <stdio.h>

static int safe_divide(int left, int right, int *result)
{
    if (right == 0 || result == NULL) {
        return 0;
    }

    *result = left / right;
    return 1;
}

int main(void)
{
#if defined(WARNING_DEMO)
    int unused = 1;
    (void)unused;
#endif

    int result;
    if (safe_divide(10, 2, &result)) {
        printf("result = %d\n", result);
    }
    return 0;
}

