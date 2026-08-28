#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char line[32];

    if (/* TODO：检查 fgets 是否失败 */) {
        if (ferror(stdin)) {
            perror("stdin");
        }
        return 1;
    }

    char *end;
    errno = 0;
    long value = strtol(line, &end, 10);

    if (/* TODO：检查转换失败和尾部 */) {
        puts("invalid number");
        return 1;
    }

    printf("value = %ld\n", value);
    return 0;
}

