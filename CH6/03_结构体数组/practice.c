#include <stdio.h>

struct Student
{
    const char *name;
    int score;
};

int main(void)
{
    struct Student students[] = {
        /* TODO：填写至少三个学生 */
    };
    size_t count = sizeof students / sizeof students[0];
    int total = 0;

    for (size_t i = 0; i < count; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
        /* TODO：累加当前分数 */
    }

    printf("average = %.2f\n", (double)total / (double)count);
    return 0;
}

