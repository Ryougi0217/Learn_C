#include <stdio.h>

int main(void)
{
#ifdef DEBUG
    puts("debug logging enabled");
#else
    puts("release logging");
#endif

#if defined(VERSION)
    printf("version = %d\n", VERSION);
#endif

    return 0;
}

