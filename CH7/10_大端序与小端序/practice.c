#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t value = UINT32_C(0x12345678);
    const unsigned char *bytes =
        /* TODO：把 value 地址转换成字节指针 */;

    for (size_t i = 0; i < sizeof value; i++) {
        printf("%02X ", /* TODO：当前字节 */);
    }
    putchar('\n');
    return 0;
}

