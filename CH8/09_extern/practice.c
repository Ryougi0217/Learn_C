#include <stdio.h>
#include "config.h"

int main(void)
{
    printf("level=%d\n", log_level);
    log_level = 2;
    printf("level=%d\n", log_level);
    return 0;
}

