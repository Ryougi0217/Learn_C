#include <stdio.h>

int main(int argc, char *argv[])
{
    const char *target = "practice";

    if (argc >= 2) {
        target = argv[1];
    }

    printf("target = %s\n", target);
    return 0;
}

