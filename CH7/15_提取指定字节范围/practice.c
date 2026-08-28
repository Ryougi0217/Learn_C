#include <stdio.h>

static int extract_range(const char *path,
                         long offset,
                         size_t length)
{
    unsigned char buffer[64];

    if (/* TODO：检查 offset 和 length */) {
        return 0;
    }

    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return 0;
    }

    if (/* TODO：定位到 offset */ != 0) {
        fclose(file);
        return 0;
    }

    size_t count = /* TODO：读取 length 个字节 */;
    if (/* TODO：检查 ferror */) {
        fclose(file);
        return 0;
    }

    fclose(file);

    for (size_t i = 0; i < count; i++) {
        printf("%02X%s", buffer[i], i + 1 == count ? "" : " ");
    }
    putchar('\n');
    return 1;
}

int main(void)
{
    return extract_range("sample.bin", 0, 16) ? 0 : 1;
}

