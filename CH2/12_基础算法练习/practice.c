#include <stdio.h>

int sum_to(int n)
{
    int sum = /* TODO 1：填写累加器初值 */;

    /* TODO 2：写出从 1 到 n 的累加循环。 */
    for (int i = /* 在这里填写 */; /* 在这里填写 */; /* 在这里填写 */) {
        /* TODO 3：把当前 i 加到 sum。 */
    }

    return sum;
}

int count_multiples(int n, int divisor)
{
    int count = /* TODO 4：填写计数器初值 */;

    for (int i = 1; /* TODO 5：填写循环条件 */; i++) {
        if (/* TODO 6：填写倍数判断 */) {
            /* TODO 7：递增 count。 */
        }
    }

    return count;
}

int is_prime(int n)
{
    /* TODO 8：处理小于 2 的情况。 */
    if (n < 2) {
        return /* 在这里填写 */;
    }

    for (int divisor = 2;
         /* TODO 9：填写检查到平方根附近的条件 */;
         divisor++) {
        if (/* TODO 10：填写整除判断 */) {
            return /* 在这里填写 */;
        }
    }

    return /* TODO 11：填写“没有找到因数”的结果 */;
}

int main(void)
{
    int n = 12;
    int divisor = 3;

    printf("sum_to(%d) = %d\n", n, sum_to(n));
    printf("倍数数量 = %d\n", count_multiples(n, divisor));

    for (int value = 0; value <= 12; value++) {
        printf("%d is %s\n",
               value,
               is_prime(value) ? "prime" : "not prime");
    }

    return 0;
}

