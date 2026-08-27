#include <stdio.h>

int main(void)
{
    int left = 17;
    int right = 5;
    int quotient = left / right;
    int remainder = left % right;
    int both_positive = left > 0 && right > 0;
    int has_remainder = remainder != 0;

    printf("quotient = %d, remainder = %d\n", quotient, remainder);
    printf("both positive = %d\n", both_positive);
    printf("has remainder = %d\n", has_remainder);

    quotient += 10;
    printf("adjusted quotient = %d\n", quotient);

    return 0;
}

