#include <stdio.h>

struct Student
{
    const char *name;
    int age;
    double score;
};

int main(void)
{
    struct Student student = /* TODO：按成员顺序初始化 */;

    printf("name = %s\n", student.name);
    printf("age = %d\n", student.age);
    printf("score = %.1f\n", student.score);

    return 0;
}

