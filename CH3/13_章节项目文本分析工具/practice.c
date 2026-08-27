#include <stdio.h>
#include <string.h>

#define TEXT_CAPACITY 128

static void trim_newline(char *text)
{
    size_t i = 0;

    while (text[i] != '\0') {
        if (text[i] == '\n' || text[i] == '\r') {
            text[i] = '\0';
            return;
        }
        i++;
    }
}

static int is_ascii_letter(char character)
{
    return (character >= 'A' && character <= 'Z') ||
           (character >= 'a' && character <= 'z');
}

static int is_ascii_digit(char character)
{
    return character >= '0' && character <= '9';
}

static int is_space_character(char character)
{
    return character == ' ' ||
           character == '\t' ||
           character == '\n' ||
           character == '\r';
}

static size_t count_letters(const char *text)
{
    size_t count = 0;

    /* TODO 1：遍历 text，只统计 ASCII 字母。 */
    for (size_t i = 0; /* 在这里填写 */; i++) {
        if (/* 在这里填写 */) {
            count++;
        }
    }

    return count;
}

static size_t count_digits(const char *text)
{
    size_t count = 0;

    /* TODO 2：遍历 text，只统计数字字符。 */
    for (size_t i = 0; /* 在这里填写 */; i++) {
        if (/* 在这里填写 */) {
            count++;
        }
    }

    return count;
}

static size_t count_words(const char *text)
{
    size_t count = 0;
    int in_word = 0;

    /*
     * TODO 3：根据“从空白进入非空白”的变化统计单词。
     * 连续多个空白只能结束当前单词，不能重复计数。
     */
    for (size_t i = 0; /* 在这里填写 */; i++) {
        if (/* 在这里填写 */) {
            in_word = 0;
        } else if (/* 在这里填写 */) {
            count++;
            in_word = 1;
        }
    }

    return count;
}

int main(void)
{
    char text[TEXT_CAPACITY];

    printf("请输入一行 ASCII 文本：");
    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "没有读到输入。\n");
        return 1;
    }

    trim_newline(text);

    printf("长度：%zu\n", strlen(text));
    printf("字母：%zu\n", count_letters(text));
    printf("数字：%zu\n", count_digits(text));
    printf("单词：%zu\n", count_words(text));

    return 0;
}

