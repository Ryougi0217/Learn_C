#include <stdio.h>

int main(void)
{
    int total = 7;
    int count = 2;

    double integer_division = total / count;

    /*
     * TODO 1：在除法前把 total 显式转换为 double。
     * 目标是让除法本身保留小数。
     */
    double floating_division = /* 在这里填写 */;

    double cast_after_division = (double) (total / count);

    double measurement = 12.75;
    int truncated = (int) measurement;

    printf("integer division = %.2f\n", integer_division);
    printf("floating division = %.2f\n", floating_division);
    printf("cast after division = %.2f\n", cast_after_division);
    printf("truncated measurement = %d\n", truncated);

    return 0;
}

