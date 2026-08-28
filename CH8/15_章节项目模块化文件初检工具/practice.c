#include <stdio.h>
#include "file_scan.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    long size = scan_file_size(argv[1]);
    if (size < 0) {
        return 1;
    }

    printf("size = %ld\n", size);
    return 0;
}

