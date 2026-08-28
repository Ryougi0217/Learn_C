#include <stdio.h>

struct Product
{
    const char *name;
    int stock;
    double price;
};

int main(void)
{
    struct Product product = {"keyboard", 3, 129.0};

    /* TODO：把库存增加 2 */
    /* TODO：把价格改成 119.0 */

    printf("%s: stock=%d price=%.1f\n",
           product.name, product.stock, product.price);
    return 0;
}

