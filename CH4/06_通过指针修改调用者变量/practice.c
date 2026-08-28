#include <stdio.h>

void set_value(int *value, int new_value)
{
    /*
     * TODO 1：只有 value 不是 NULL 时，才通过解引用写入 new_value。
     */
    if (/* 在这里填写 */) {
        /* 在这里填写 */
    }
}

int main(void)
{
    int score = 95;

    /*
     * TODO 2：传入 score 的地址和新值 100。
     */
    set_value(/* 在这里填写 */, /* 在这里填写 */);
    printf("score = %d\n", score);

    set_value(NULL, 50);
    printf("score after NULL call = %d\n", score);

    return 0;
}

