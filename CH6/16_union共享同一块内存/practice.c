#include <stdio.h>

union Storage
{
    int number;
    char text[sizeof(int)];
};

int main(void)
{
    union Storage storage = {.number = 0x12345678};

    printf("&storage = %p\n", (void *)&storage);
    printf("&storage.number = %p\n", (void *)&storage.number);
    printf("&storage.text = %p\n", (void *)&storage.text);

    /* TODO：写入 text[0]，再打印它 */
    printf("text[0] = %c\n", storage.text[0]);
    return 0;
}

