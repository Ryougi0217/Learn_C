#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    size_t length = sizeof values / sizeof values[0];

    /*
     * 先保留 <=，用 Sanitizer 观察越界。
     * 修复时改为 i < length。
     */
    for (size_t i = 0; i <= length; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
    }

    return 0;
}

