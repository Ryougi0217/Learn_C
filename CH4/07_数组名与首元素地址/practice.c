#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};

    /* TODO 1：让 first 指向 values 的首元素。 */
    int *first = /* 在这里填写 */;

    printf("values address = %p\n", (void *) values);
    printf("first address = %p\n", (void *) first);
    printf("first[1] = %d\n", first[1]);
    printf("*(first + 3) = %d\n", *(first + 3));

    return 0;
}

