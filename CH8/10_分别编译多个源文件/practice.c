#include <stdio.h>
#include "stats.h"

int main(void)
{
    int values[] = {2, 4, 6};
    printf("%d\n", sum_ints(values, 3));
    return 0;
}

