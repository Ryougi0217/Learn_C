#include <stdio.h>
#include "greet.h"
#include "math.h"

int main(void)
{
    printf("%s %d\n", greeting(), triple(4));
    return 0;
}

