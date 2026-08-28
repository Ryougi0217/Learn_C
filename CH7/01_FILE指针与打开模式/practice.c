#include <stdio.h>

int main(void)
{
    FILE *file = fopen(/* TODO：文件名 */, /* TODO：打开模式 */);

    if (file == NULL) {
        fputs("open failed\n", stderr);
        return 1;
    }

    puts("file opened");
    /* TODO：关闭 file */

    return 0;
}

