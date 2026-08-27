#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[16] = "hello";
    size_t capacity = sizeof buffer;
    size_t length = strlen(buffer);
    char next = '!';

    /*
     * TODO 1：只有在能同时放下 next 和新的 '\0' 时才追加。
     */
    if (/* 在这里填写容量条件 */) {
        buffer[length] = next;
        buffer[length + 1] = '\0';
    }

    printf("buffer = %s\n", buffer);
    printf("length = %zu\n", strlen(buffer));
    printf("capacity = %zu\n", capacity);

    return 0;
}

