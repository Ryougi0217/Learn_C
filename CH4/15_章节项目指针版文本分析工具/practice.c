#include <stdio.h>
#include <string.h>

#define TEXT_CAPACITY 128

static void trim_newline(char *text)
{
    while (*text != '\0') {
        if (*text == '\n' || *text == '\r') {
            *text = '\0';
            return;
        }

        text++;
    }
}

static int is_ascii_letter(char c)
{
    return (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z');
}

static int is_ascii_digit(char c)
{
    return c >= '0' && c <= '9';
}

static int is_space_character(char c)
{
    return c == ' '
        || c == '\t'
        || c == '\n'
        || c == '\r';
}

static size_t count_letters_ptr(const char *text)
{
    size_t count = 0;
    const char *cursor = /* TODO: 从 text 开始 */;

    while (/* TODO: 游标没有到字符串末尾 */) {
        if (/* TODO: 当前字符是 ASCII 字母 */) {
            count++;
        }

        /* TODO: 移动到下一个字符 */
    }

    return count;
}

static size_t count_digits_ptr(const char *text)
{
    size_t count = 0;
    const char *cursor = /* TODO: 从 text 开始 */;

    while (/* TODO: 游标没有到字符串末尾 */) {
        if (/* TODO: 当前字符是 ASCII 数字 */) {
            count++;
        }

        /* TODO: 移动到下一个字符 */
    }

    return count;
}

static size_t count_words_ptr(const char *text)
{
    size_t count = 0;
    int in_word = 0;
    const char *cursor = /* TODO: 从 text 开始 */;

    while (/* TODO: 游标没有到字符串末尾 */) {
        if (/* TODO: 当前字符是空白 */) {
            in_word = 0;
        } else if (/* TODO: 当前字符是单词的第一个字符 */) {
            count++;
            /* TODO: 标记已经进入单词 */
        }

        /* TODO: 移动到下一个字符 */
    }

    return count;
}

int main(void)
{
    char text[TEXT_CAPACITY];

    printf("Enter one line: ");
    if (fgets(text, sizeof text, stdin) == NULL) {
        fputs("input error\n", stderr);
        return 1;
    }

    trim_newline(text);

    printf("length = %zu\n", strlen(text));
    printf("letters = %zu\n", count_letters_ptr(text));
    printf("digits = %zu\n", count_digits_ptr(text));
    printf("words = %zu\n", count_words_ptr(text));

    return 0;
}

