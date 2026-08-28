#include <stdio.h>

int main(void)
{
    char text[] = "hello";

    /* TODO 1：让 cursor 指向 text 的首字符。 */
    char *cursor = /* 在这里填写 */;
    size_t length = 0;

    /*
     * TODO 2：只要当前字符不是 '\0' 就继续。
     */
    while (/* 在这里填写 */) {
        printf("character = %c\n", /* 在这里填写 */);
        /* TODO 3：推进 cursor，并更新 length。 */
    }

    printf("length = %zu\n", length);
    return 0;
}

