# 第 15 课：章节项目——指针版文本分析工具

## 项目目标

在 CH3 中，我们用数组下标遍历文本。本课把核心遍历改成指针游标：

```c
const char *cursor = text;

while (*cursor != '\0') {
    /* 处理 *cursor */
    cursor++;
}
```

项目读取一行文本，并统计：

- 文本长度；
- ASCII 英文字母数量；
- ASCII 数字数量；
- 单词数量。

项目的重点不是新增库函数，而是练习：

- 指针保存当前位置；
- `*cursor` 读取当前位置的字符；
- `cursor++` 移动到下一个字符；
- 把只读文本传给 `const char *` 参数；
- 把可修改文本传给 `char *` 参数。

## 1. 三种等价的访问方式

假设 `text` 指向字符串的第一个字符：

```c
text[i]
*(text + i)
*cursor
```

当 `cursor` 恰好等于 `text + i` 时，三种写法访问的是同一个字符。

本项目要求统计函数的核心循环使用指针游标，不能把主要逻辑改回数组下标。

字符串仍然必须在 `\0` 处停止。指针遍历不会自动知道数组长度，因此必须保证：

- 输入缓冲区足够大；
- `fgets` 不会越界；
- 循环条件检查 `*cursor != '\0'`；
- 不在字符串末尾继续递增后解引用。

## 2. 准备好的辅助函数

下面三个辅助函数已经完成。它们分别判断字符是否为字母、数字或空白字符。

```c
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
```

`trim_newline` 也已经完成，它使用 `char *` 修改输入缓冲区：

```c
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
```

这个函数体现了“指针既可以读取，也可以写入”：

- `*text` 读取当前位置；
- `*text = '\0';` 把换行符替换成字符串结束符；
- `text++` 移动游标。

## 3. 完整参考实现

先阅读并运行同一份逻辑的完整版本，再打开 `practice.c` 手写统计函数。

```c
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
    const char *cursor = text;

    while (*cursor != '\0') {
        if (is_ascii_letter(*cursor)) {
            count++;
        }

        cursor++;
    }

    return count;
}

static size_t count_digits_ptr(const char *text)
{
    size_t count = 0;
    const char *cursor = text;

    while (*cursor != '\0') {
        if (is_ascii_digit(*cursor)) {
            count++;
        }

        cursor++;
    }

    return count;
}

static size_t count_words_ptr(const char *text)
{
    size_t count = 0;
    int in_word = 0;
    const char *cursor = text;

    while (*cursor != '\0') {
        if (is_space_character(*cursor)) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }

        cursor++;
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
```

可以用下面的输入测试：

```text
C pointers 3
```

预期统计结果：

```text
length = 12
letters = 9
digits = 1
words = 3
```

## 4. 练习任务

`practice.c` 保留了程序框架。主函数和辅助判断函数已经给出，你需要手写三个统计函数。

### 任务 A：统计字母

完成 `count_letters_ptr`：

- 创建 `const char *cursor`；
- 让它从 `text` 开始；
- 只要 `*cursor` 不是 `\0` 就继续；
- 当前字符是字母时递增 `count`；
- 每轮最后让游标前进。

### 任务 B：统计数字

完成 `count_digits_ptr`：

- 不要复制字母函数后忘记替换判断函数；
- 使用 `is_ascii_digit(*cursor)`；
- 仍然必须移动游标；
- 输入中没有数字时结果应为 `0`。

### 任务 C：统计单词

完成 `count_words_ptr`：

- 使用 `in_word` 记录是否已经处于单词内部；
- 空白字符会让 `in_word` 回到 `0`；
- 非空白字符且当前不在单词中时，单词数量加一；
- 进入单词后把 `in_word` 设为 `1`；
- 每轮必须移动游标。

### 任务 D：边界测试

至少测试：

```text
hello
C 101
   many   spaces
12345
one-two
```

回答：

1. 空输入的单词数是多少？
2. 连续多个空格为什么不会重复计数？
3. 连字符 `-` 在当前规则中是空白字符吗？
4. 为什么统计函数的参数使用 `const char *`？

## 5. 编译与测试

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

也可以通过管道输入，方便重复测试：

```sh
printf 'C pointers 3\n' | ./practice
```

## 本课检查点

- [ ] 我能用指针游标遍历以 `\0` 结尾的字符串。
- [ ] 我能区分 `cursor` 和 `*cursor`。
- [ ] 我实际手写了至少一个完整统计函数。
- [ ] 我没有在游标移动后越过字符串结束符再解引用。
- [ ] 我能解释为什么只读统计函数使用 `const char *`。

