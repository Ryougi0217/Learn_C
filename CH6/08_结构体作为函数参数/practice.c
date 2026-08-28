#include <stdio.h>

struct Student
{
    const char *name;
    int score;
};

static void print_student(const struct Student *student)
{
    if (/* TODO：判断 student 是否为空 */) {
        return;
    }

    printf("%s: %d\n", student->name, student->score);
}

static void raise_score(struct Student *student, int amount)
{
    /* TODO：安全地通过指针修改 score */
}

int main(void)
{
    struct Student student = {"A", 90};

    print_student(/* TODO：传入 student 地址 */);
    raise_score(/* TODO：传入 student 地址 */, 5);
    print_student(&student);
    return 0;
}

