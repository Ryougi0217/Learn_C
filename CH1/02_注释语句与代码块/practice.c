#include <stdio.h>

int main(void)
{
    int outer_value = 10;

    // 这是外层代码块。
    {
        /*
         * 内层代码块有自己的局部变量。
         * 观察它和 outer_value 的可见范围。
         */
        int inner_value = 20;
        printf("outer = %d, inner = %d\n", outer_value, inner_value);
    }

    printf("代码块执行结束，outer = %d\n", outer_value);
    return 0;
}

