#include <stdio.h>

/* 函数声明已经给出：它描述了调用者可以使用的接口。 */
int double_value(int value);

int double_value(int value)
{
    /*
     * TODO 1：手写函数体的返回表达式。
     * 让这个函数返回 value 的两倍。
     */
    return /* 在这里填写 */;
}

int main(void)
{
    int input = 7;

    /*
     * TODO 2：填写传给 double_value 的实参。
     * 先调用一次，再尝试调用第二次。
     */
    int result = double_value(/* 在这里填写 */);

    printf("result = %d\n", result);
    return 0;
}

