#include <stdio.h>

union Payload
{
    char byte;
    int number;
    double decimal;
    char bytes[16];
};

int main(void)
{
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(union Payload) = %zu\n", sizeof(union Payload));
    return 0;
}

