#include <stdio.h>

#if defined(TRY_BROKEN)
static int broken_example(void)
{
    int value = 7
    return value;
}
#endif

int main(void)
{
    int numerator = 7;
    int denominator = 2;
    int unused_value = 99;
    double average = (double) numerator / denominator;

    /*
     * 这行故意制造格式警告：
     * double 不应该使用 %d 输出。
     * 请先观察诊断，再把它修成零警告版本。
     */
    printf("average = %d\n", average);

    (void) unused_value;

#if defined(TRY_BROKEN)
    printf("修复后的示例值：%d\n", broken_example());
#endif

    return 0;
}

