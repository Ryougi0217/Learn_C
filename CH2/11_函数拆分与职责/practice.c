#include <stdio.h>

int calculate_total(int first, int second, int third)
{
    /* TODO 1：只计算总分，不要在这里打印。 */
    return /* 在这里填写 */;
}

double calculate_average(int total, int count)
{
    /* TODO 2：只计算平均分，并避免整数除法截断。 */
    return /* 在这里填写 */;
}

void print_report(int first, int second, int third, int total, double average)
{
    /* TODO 3：只负责打印成绩报告。 */
}

int main(void)
{
    int first = 88;
    int second = 92;
    int third = 76;

    int total = calculate_total(first, second, third);
    double average = calculate_average(total, 3);

    print_report(first, second, third, total, average);
    return 0;
}

