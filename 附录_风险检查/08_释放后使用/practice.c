#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);
    if (value == NULL) {
        return 1;
    }

    *value = 12;
    printf("before free = %d\n", *value);

    /* TODO：释放 value 后立即置空 */
    puts("safe after free");
    return 0;
}

