#include <stdio.h>

size_t manual_length(const char *text)
{
    size_t length = 0;

    /*
     * TODO 1：循环扫描 text，直到遇到 '\0'。
     */
    while (/* 在这里填写 */) {
        /* TODO 2：递增 length。 */
    }

    return length;
}

void manual_copy(char *destination,
                 size_t capacity,
                 const char *source)
{
    if (capacity == 0) {
        return;
    }

    size_t i = 0;

    /*
     * TODO 3：在容量允许且 source 尚未结束时复制字符。
     * 每轮都要推进 i。
     */
    while (/* 在这里填写 */) {
        /* 在这里填写复制语句和 i 的更新 */
    }

    /* TODO 4：写入 destination 的字符串结尾。 */
    destination[/* 在这里填写 */] = /* 在这里填写 */;
}

void reverse_in_place(char *text)
{
    size_t length = manual_length(text);

    /*
     * TODO 5：只遍历到字符串中间，并交换首尾字符。
     */
    for (size_t left = /* 在这里填写 */;
         /* 在这里填写 */;
         /* 在这里填写 */) {
        size_t right = /* 在这里填写 */;
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
    }
}

int main(void)
{
    char source[] = "Bootdev";
    char copied[32];

    manual_copy(copied, sizeof copied, source);

    printf("source length = %zu\n", manual_length(source));
    printf("copied = %s\n", copied);

    reverse_in_place(copied);
    printf("reversed = %s\n", copied);

    return 0;
}

