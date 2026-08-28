#include <stddef.h>
#include <stdio.h>

struct Mixed
{
    char flag;
    int count;
    double ratio;
};

int main(void)
{
    printf("sizeof(struct Mixed) = %zu\n", sizeof(struct Mixed));
    printf("offset flag = %zu\n", offsetof(struct Mixed, flag));
    printf("offset count = %zu\n", offsetof(struct Mixed, count));
    printf("offset ratio = %zu\n", offsetof(struct Mixed, ratio));
    return 0;
}

