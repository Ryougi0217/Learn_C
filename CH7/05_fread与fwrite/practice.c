#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const uint32_t values[] = {10, 20, 30};
    uint32_t loaded[3];
    FILE *file = fopen("numbers.bin", /* TODO：二进制写入模式 */);

    if (file == NULL) {
        return 1;
    }

    size_t count = sizeof values / sizeof values[0];

    if (/* TODO：用 fwrite 写入 values */ != count) {
        fclose(file);
        return 1;
    }
    fclose(file);

    file = fopen("numbers.bin", /* TODO：二进制读取模式 */);
    if (file == NULL) {
        return 1;
    }

    size_t read_count = /* TODO：用 fread 读入 loaded */;
    printf("read %zu values\n", read_count);

    fclose(file);
    return read_count == count ? 0 : 1;
}

