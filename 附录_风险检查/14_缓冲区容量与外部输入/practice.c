#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[8];

    if (/* TODO：使用 sizeof name 限制 fgets */) {
        return 1;
    }

    char *newline = /* TODO：查找换行符 */;
    if (newline != NULL) {
        *newline = '\0';
    }

    printf("name = %s\n", name);
    return 0;
}

