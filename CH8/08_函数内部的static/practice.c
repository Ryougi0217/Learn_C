#include <stdio.h>

static int next_id(void)
{
    /* TODO：声明只初始化一次的局部 static 变量 */
    return current++;
}

int main(void)
{
    printf("%d\n", next_id());
    printf("%d\n", next_id());
    printf("%d\n", next_id());
    return 0;
}

