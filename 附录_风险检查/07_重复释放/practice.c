#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);
    if (value == NULL) {
        return 1;
    }

    *value = 3;
    printf("%d\n", *value);

    /* TODO：释放 value 并置空 */
    puts("released once");
    return 0;
}

