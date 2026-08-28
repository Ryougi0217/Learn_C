#include <stdio.h>

static int has_tail(const char *path, long valid_end)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return -1;
    }

    if (/* TODO：移动到末尾 */ != 0) {
        fclose(file);
        return -1;
    }

    long file_size = /* TODO：读取文件大小 */;
    fclose(file);

    if (file_size < 0) {
        return -1;
    }

    return file_size > valid_end;
}

int main(void)
{
    int result = has_tail("sample.bin", 8);

    if (result < 0) {
        puts("could not inspect file");
        return 1;
    }

    puts(result ? "extra tail exists" : "no extra tail");
    return 0;
}

