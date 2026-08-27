#include <stdio.h>

int main(void)
{
    int number;

    printf("请输入一个整数：");

    /*
     * TODO 1：这是本课的新库函数调用。
     * 填写 "%d" 和 number 的地址。
     */
    int matched = scanf(/* 在这里填写 */, /* 在这里填写 */);

    if (matched == 1) {
        printf("读取到 number = %d\n", number);
    } else {
        printf("输入不是一个可识别的整数。\n");
    }

    printf("scanf matched fields = %d\n", matched);
    return 0;
}

