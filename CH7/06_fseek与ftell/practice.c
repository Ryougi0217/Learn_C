#include <stdio.h>

int main(void)
{
    FILE *file = fopen("numbers.bin", "rb");

    if (file == NULL) {
        return 1;
    }

    if (/* TODO：移动到文件末尾 */ != 0) {
        fclose(file);
        return 1;
    }

    long size = /* TODO：读取当前位置 */;
    if (size < 0) {
        fclose(file);
        return 1;
    }

    printf("file size = %ld\n", size);

    /* TODO：回到文件开头 */
    fclose(file);
    return 0;
}

