#include <stdio.h>

int main(void)
{
    double price = 19.90;
    int quantity = 3;
    double total = price * quantity;
    double sum = 0.1 + 0.2;
    float ratio = 1.0f / 3.0f;

    printf("total = %.2f\n", total);
    printf("0.1 + 0.2 = %.17f\n", sum);
    printf("float ratio = %.7f\n", ratio);

    return 0;
}

