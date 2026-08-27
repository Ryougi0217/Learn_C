#include <stdio.h>

int sum_to(int n)
{
    /*
     * TODO 1：填写递归基础情况。
     * n <= 0 时不再调用自己。
     */
    if (/* 在这里填写 */) {
        return /* 在这里填写 */;
    }

    printf("进入 sum_to(%d)\n", n);

    /*
     * TODO 2：手写递归情况。
     * 当前 n 应与更小的 n - 1 组合。
     */
    return /* 在这里填写 */;
}

int main(void)
{
    int n = 5;
    int result = sum_to(n);

    printf("1 到 %d 的总和是 %d\n", n, result);
    return 0;
}

