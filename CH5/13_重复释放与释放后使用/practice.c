#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);

    if (value == NULL) {
        return 1;
    }

    *value = 10;
    printf("before release = %d\n", *value);

#if defined(DOUBLE_FREE) || defined(USE_AFTER_FREE)
    int *alias = /* TODO：保存 value 的别名 */;
#endif

    free(value);
    value = NULL;

#if defined(USE_AFTER_FREE)
    /* TODO：仅在 Sanitizer 诊断中通过 alias 读取 */
    puts("diagnostic use-after-free");
#elif defined(DOUBLE_FREE)
    /* TODO：仅在 Sanitizer 诊断中释放 alias */
    puts("diagnostic double-free");
#else
    puts("safe path");
#endif

    return 0;
}

