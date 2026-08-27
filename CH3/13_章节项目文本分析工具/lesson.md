# 第 13 课：章节项目——文本分析工具

## 项目目标

编写一个只处理一行 ASCII 文本的分析工具，输出：

- 文本长度（不包含结尾的 `\0`）；
- ASCII 字母数量；
- 数字字符数量；
- 空白分隔出的单词数量；
- 是否成功读取输入。

本项目重点不是支持所有语言文字，而是练习数组、字符串结尾、逐行输入、循环和函数拆分。

## 1. 先明确约束

本项目使用：

- 固定容量为 128 的字符数组；
- `fgets` 读取一行；
- 手动移除 `\n` 或 `\r`；
- ASCII 范围内的字母和数字判断；
- 连续空白视为一个分隔区域。

例如：

```text
输入：C has 3 arrays
长度：14
字母：10
数字：1
单词：4
```

项目只统计当前缓冲区中成功读入的内容。超过 127 个字符的长行需要更复杂的输入清理，本课先记录这个限制。

## 2. 函数职责

可以把程序拆成：

- `trim_newline`：清理输入结尾；
- `count_letters`：统计 ASCII 字母；
- `count_digits`：统计数字；
- `count_words`：根据空白变化统计单词；
- `main`：读取输入并打印报告。

计算函数只返回结果，不在内部打印，这样更容易测试。

## 3. 完整参考实现

```c
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

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (is_ascii_letter(text[i])) {
            count++;
        }
    }

    return count;
}

static size_t count_digits(const char *text)
{
    size_t count = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (is_ascii_digit(text[i])) {
            count++;
        }
    }

    return count;
}

static size_t count_words(const char *text)
{
    size_t count = 0;
    int in_word = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (is_space_character(text[i])) {
            in_word = 0;
        } else if (!in_word) {
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
```

## 项目任务

1. 完成练习脚本中的三个统计函数；
2. 测试空行、单词、多个空格、制表符、字母和数字混合文本；
3. 测试没有数字、没有字母和全部是空白的输入；
4. 记录你的“单词”定义；
5. 说明程序的 ASCII 限制；
6. 使用 `-Wall -Wextra -Wconversion -pedantic` 编译；
7. 可选：处理超长输入，说明你如何判断一行是否还没有读完。

## 自测题

1. 为什么项目要先移除换行符再统计长度？
2. `count_words` 为什么需要 `in_word` 状态？
3. 连续多个空格为什么不应该统计成多个单词？
4. 为什么计算函数不直接打印结果？
5. 这个项目对中文文本的统计有什么限制？
6. 如果 `fgets` 失败，为什么不能继续分析数组内容？

## 验收标准

- [ ] 能读取一行文本并检查返回值；
- [ ] 能正确统计长度、字母、数字和单词；
- [ ] 能处理空行和连续空白；
- [ ] 能说明固定容量和 ASCII 限制；
- [ ] 主要逻辑已经拆成职责清晰的函数。


