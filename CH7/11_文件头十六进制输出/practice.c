#include <stdio.h>

static int print_header(const char *path)
{
    FILE *file = /* TODO：只读二进制打开 */;
    if (file == NULL) {
        return 0;
    }

    unsigned char header[16];
    size_t count = /* TODO：读取最多 16 个字节 */;

    if (/* TODO：检查 ferror */) {
        fclose(file);
        return 0;
    }

    fclose(file);

    for (size_t i = 0; i < count; i++) {
        printf("%02X%s", header[i], i + 1 == count ? "" : " ");
    }
    putchar('\n');
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    return print_header(argv[1]) ? 0 : 1;
}

