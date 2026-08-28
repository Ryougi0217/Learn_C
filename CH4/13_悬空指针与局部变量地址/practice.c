#include <stdio.h>

static int write_value(int *destination)
{
    if (destination == NULL) {
        return 0;
    }

    *destination = 42;
    return 1;
}

#if defined(TRY_DANGLING)
static int *make_dangling_pointer(void)
{
    int local = 42;

    return &local;
}
#endif

int main(void)
{
    int result = 0;

    if (write_value(&result)) {
        printf("safe result = %d\n", result);
    }

#if defined(TRY_DANGLING)
    int *dangling = make_dangling_pointer();

    printf("dangling address = %p\n", (void *)dangling);
    printf("dangling value = %d\n", *dangling); /* 仅用于诊断练习 */
#else
    printf("default path does not dereference a dangling pointer\n");
#endif

    return 0;
}

