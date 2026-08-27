#include <stdio.h>

int main(void)
{
    int option = 2;

    switch (option) {
    case 1:
        printf("执行：查看成绩\n");
        break;
    case 2:
        printf("执行：开始练习\n");
        break;
    case 3:
        printf("执行：退出程序\n");
        break;
    default:
        printf("未知选项\n");
        break;
    }

    return 0;
}

