#include <stdio.h>

struct Student
{
    const char *name;
    int score;
};

int main(void)
{
    struct Student student = {"A", 80};
    struct Student *pointer = /* TODO：指向 student */;

    /* TODO：用 -> 把分数增加 5 */

    printf("%s: %d\n", pointer->name, pointer->score);
    printf("same score = %d\n", (*pointer).score);
    return 0;
}

