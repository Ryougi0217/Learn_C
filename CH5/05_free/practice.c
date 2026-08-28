#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);

    if (value == NULL) {
        return 1;
    }

    *value = 123;
    printf("before free = %d\n", *value);

    /* TODO 1：释放 value */
    /* TODO 2：把 value 设为 NULL */

    printf("pointer after free = %s\n",
           value == NULL ? "NULL" : "not NULL");

    return 0;
}

