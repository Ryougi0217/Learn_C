#include <stdio.h>

int main(void)
{
    FILE *file = fopen("report.txt", /* TODO：文本覆盖写入模式 */);

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    if (/* TODO：使用 fprintf 写入格式化内容 */ < 0) {
        perror("fprintf");
        fclose(file);
        return 1;
    }

    if (/* TODO：使用 fputs 写入状态行 */ == EOF) {
        perror("fputs");
        fclose(file);
        return 1;
    }

    /* TODO：检查 fclose */
    return 0;
}

