#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    size_t count = sizeof values / sizeof values[0];

    /* TODO 1：让 begin 指向首元素。 */
    int *begin = /* 在这里填写 */;

    /* TODO 2：让 end 指向数组末尾后一格。 */
    int *end = /* 在这里填写 */;

    int sum = 0;

    /*
     * TODO 3：用 current 从 begin 走到 end，
     * 每轮把当前元素加到 sum。
     */
    for (int *current = begin; /* 在这里填写 */; /* 在这里填写 */) {
        sum += /* 在这里填写 */;
    }

    printf("sum = %d\n", sum);
    printf("distance = %td\n", end - begin);

    return 0;
}

