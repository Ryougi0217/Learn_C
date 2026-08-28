#include <stdio.h>
#include <string.h>

static const char *detect_signature(const unsigned char *data,
                                    size_t count)
{
    static const unsigned char png[] = {
        0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A
    };

    if (/* TODO：长度足够且匹配 PNG */) {
        return "PNG";
    }
    if (/* TODO：长度足够且匹配 PDF */) {
        return "PDF";
    }
    return "unknown";
}

int main(void)
{
    const unsigned char data[] = {0x7F, 'E', 'L', 'F'};
    printf("format = %s\n",
           detect_signature(data, sizeof data));
    return 0;
}

