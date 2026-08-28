#include <stdio.h>
#include "counter.h"

int main(void)
{
    int first = next_counter();
    int second = next_counter();

    printf("%d %d\n", first, second);
    return 0;
}

