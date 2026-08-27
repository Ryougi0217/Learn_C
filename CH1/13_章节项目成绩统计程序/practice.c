#include <stdio.h>

int main(void)
{
    int score1;
    int score2;
    int score3;

    printf("请输入三门成绩（0 到 100），用空格分隔：");
    int matched = scanf("%d %d %d", &score1, &score2, &score3);

    if (matched != 3) {
        printf("输入格式错误：需要三个整数。\n");
        return 1;
    }

    /*
     * TODO 1：拒绝小于 0 或大于 100 的成绩。
     * 三个成绩中任意一个越界，都应进入错误分支。
     */
    if (/* 在这里填写 */) {
        printf("成绩范围错误：每门成绩应在 0 到 100 之间。\n");
        return 1;
    }

    int total = score1 + score2 + score3;

    /*
     * TODO 2：使用显式类型转换计算平均分，避免整数除法截断。
     */
    double average = /* 在这里填写 */;

    printf("成绩：%d、%d、%d\n", score1, score2, score3);
    printf("总分：%d\n", total);
    printf("平均分：%.2f\n", average);
    printf("结果：%s\n", average >= 60.0 ? "通过" : "继续练习");

    return 0;
}

