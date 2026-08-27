#include <stdio.h>

static void trim_newline(char *text)
{
    size_t i = 0;

    while (text[i] != '\0') {
        /*
         * TODO 1：判断当前字符是否为 '\n' 或 '\r'。
         */
        if (/* 在这里填写 */) {
            /*
             * TODO 2：把换行位置改为字符串结尾。
             */
            text[i] = /* 在这里填写 */;
            return;
        }

        i++;
    }
}

int main(void)
{
    char line[64];

    printf("请输入一行文字：");
    if (fgets(line, sizeof line, stdin) == NULL) {
        return 1;
    }

    trim_newline(line);
    printf("清理后：[%s]\n", line);
    return 0;
}

