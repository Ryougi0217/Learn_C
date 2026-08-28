#include <stdio.h>
#include <stddef.h>

static int max_ints(const int values[], size_t count)
{
    if (count == 0) {
        return 0;
    }

    int maximum = values[0];
    for (size_t i = 1; i < count; i++) {
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }
    return maximum;
}

int main(void)
{
    int one[] = {42};

    printf("empty = %d\n", max_ints(NULL, 0));
    printf("single = %d\n", max_ints(one, 1));
    return 0;
}

