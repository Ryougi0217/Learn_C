#include <stdio.h>

int main(void)
{
    int value = 42;

#if defined(BROKEN_SEMICOLON)
    /* 故意漏掉分号；使用 -DBROKEN_SEMICOLON 时修复这一行。 */
    int broken_value = 7
    printf("broken value = %d\n", broken_value);
#endif

#if defined(BROKEN_NAME)
    /* 故意使用未声明的名称；使用 -DBROKEN_NAME 时修复这一行。 */
    printf("unknown value = %d\n", missing_name);
#endif

#if defined(BROKEN_PAREN)
    /* 故意漏掉右括号；使用 -DBROKEN_PAREN 时修复这一行。 */
    printf("this call is broken\n";
#endif

    printf("normal value = %d\n", value);
    return 0;
}

