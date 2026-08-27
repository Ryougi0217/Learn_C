#include <limits.h>
#include <stdio.h>

int main(void)
{
    int signed_value = -1;
    unsigned int unsigned_value = 3u;
    unsigned int wrapped = 0u - 1u;
    int mixed_result = signed_value < unsigned_value;

    printf("signed value = %d\n", signed_value);
    printf("unsigned value = %u\n", unsigned_value);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("unsigned underflow = %u\n", wrapped);
    printf("signed < unsigned ? %s\n",
           mixed_result ? "true" : "false");

    return 0;
}

