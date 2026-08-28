#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_score(const char *text, int *score)
{
    if (/* TODO：检查空参数和空字符串 */) {
        return 0;
    }

    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);

    if (/* TODO：检查转换失败、尾部字符和 0~100 范围 */) {
        return 0;
    }

    *score = (int)value;
    return 1;
}

int main(void)
{
    int score;
    printf("%d\n", parse_score("99", &score));
    printf("%d\n", parse_score("101", &score));
    return 0;
}

