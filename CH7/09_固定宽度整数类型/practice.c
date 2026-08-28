#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t magic = /* TODO：初始化固定宽度无符号整数 */;
    int16_t offset = /* TODO：初始化固定宽度有符号整数 */;

    printf("magic = 0x%" PRIX32 "\n", magic);
    printf("offset = %" PRId16 "\n", offset);
    return 0;
}

