#include <stdio.h>

int main(void)
{
    const unsigned char bytes[] = {0x41, 0x00, 0x42, 0xff};
    unsigned char loaded[sizeof bytes];

    FILE *file = fopen("sample.bin", /* TODO：二进制写模式 */);
    if (file == NULL) {
        return 1;
    }

    if (/* TODO：写入 bytes */ != sizeof bytes) {
        fclose(file);
        return 1;
    }
    fclose(file);

    file = fopen("sample.bin", /* TODO：二进制读模式 */);
    if (file == NULL) {
        return 1;
    }

    size_t count = /* TODO：读回 loaded */;
    fclose(file);

    for (size_t i = 0; i < count; i++) {
        printf("%02X ", loaded[i]);
    }
    putchar('\n');
    return 0;
}

