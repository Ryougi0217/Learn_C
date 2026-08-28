#include <stdio.h>
#include <string.h>

static long file_size(FILE *file)
{
    if (/* TODO：移动到末尾 */ != 0) {
        return -1;
    }

    long size = /* TODO：读取位置 */;
    if (size < 0 || /* TODO：回到开头 */ != 0) {
        return -1;
    }

    return size;
}

static const char *detect_format(const unsigned char *header,
                                 size_t count)
{
    if (/* TODO：检测 PDF */) {
        return "PDF";
    }
    if (/* TODO：检测 ELF */) {
        return "ELF";
    }
    return "unknown";
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    long size = file_size(file);
    if (size < 0) {
        fclose(file);
        return 1;
    }

    unsigned char header[16];
    size_t count = /* TODO：读取头部 */;
    if (/* TODO：检查 ferror */) {
        fclose(file);
        return 1;
    }

    printf("size = %ld\n", size);
    printf("format = %s\n", detect_format(header, count));

    if (fclose(file) != 0) {
        return 1;
    }

    return 0;
}

