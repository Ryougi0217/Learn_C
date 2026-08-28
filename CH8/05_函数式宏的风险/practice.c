#include <stdio.h>

#define BAD_SQUARE(x) /* TODO：故意写出没有完整括号的宏 */
#define SQUARE(x) /* TODO：写出安全括号版本 */

static int square_int(int value)
{
    /* TODO：用真正的函数计算平方 */
}

int main(void)
{
    printf("bad precedence = %d\n", 2 + BAD_SQUARE(3));
    printf("safe macro = %d\n", 2 + SQUARE(3));
    printf("function = %d\n", square_int(3));
    return 0;
}

