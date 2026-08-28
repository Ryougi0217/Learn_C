#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *first = malloc(sizeof *first);
    int *second = malloc(sizeof *second);

    if (first == NULL || second == NULL) {
        free(first);
        free(second);
        return 1;
    }

    *first = 1;
    *second = 2;
    printf("%d %d\n", *first, *second);

#if defined(LEAK_DEMO)
    puts("diagnostic path: intentionally skipping free");
#else
    /* TODO：安全路径中释放 first 和 second */
    first = NULL;
    second = NULL;
#endif

    return 0;
}

