#include <stdio.h>

int main(void)
{
    FILE *file = fopen("example.txt", /* TODO：写入模式 */);

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    /* TODO：写入一行文本 */

    if (/* TODO：检查 fclose 是否成功 */) {
        perror("fclose");
        return 1;
    }

    return 0;
}

