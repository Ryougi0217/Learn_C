#include <stdio.h>
#include "counter.h"

int main(void)
{
    int first = counter_next();
    int second = counter_next();

    printf("%d %d\n", first, second);
    return 0;
}

