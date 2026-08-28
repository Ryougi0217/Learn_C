#include <stdio.h>
#include <string.h>

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
        return 1;
    }

    if (/* TODO：移动到末尾 */ != 0) {
        fclose(file);
        return 1;
    }
    long size = /* TODO：读取大小 */;
    if (size < 0 || /* TODO：回到开头 */ != 0) {
        fclose(file);
        return 1;
    }

    unsigned char header[16];
    size_t count = /* TODO：读取头部 */;
    if (/* TODO：检查读取错误 */) {
        fclose(file);
        return 1;
    }
    fclose(file);

    printf("size=%ld format=%s header_bytes=%zu\n",
           size, detect_format(header, count), count);
    return 0;
}

