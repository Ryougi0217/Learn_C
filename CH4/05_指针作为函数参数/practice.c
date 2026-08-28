#include <stdio.h>

void print_pointed_value(const int *value)
{
    /*
     * TODO 1：如果 value 为 NULL，先打印提示并 return。
     */
    if (/* 在这里填写 */) {
        printf("没有可读取的整数。\n");
        return;
    }

    /* TODO 2：通过解引用打印 value 指向的整数。 */
    printf("pointed value = %d\n", /* 在这里填写 */);
}

int main(void)
{
    int score = 95;

    /*
     * TODO 3：把 score 的地址传给函数。
     */
    print_pointed_value(/* 在这里填写 */);
    print_pointed_value(NULL);

    return 0;
}

