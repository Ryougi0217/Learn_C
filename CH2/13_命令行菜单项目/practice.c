#include <stdio.h>

void show_menu(void)
{
    printf("\n=== C 学习菜单 ===\n");
    printf("1. 打招呼\n");
    printf("2. 计算 1 到 n 的总和\n");
    printf("3. 显示学习提示\n");
    printf("0. 退出\n");
    printf("请选择：");
}

void print_greeting(void)
{
    printf("你好，继续练习 C！\n");
}

int sum_to(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        /* TODO 1：把当前 i 累加到 sum。 */
    }

    return sum;
}

int run_sum_demo(void)
{
    int n;

    printf("请输入 n：");
    if (scanf("%d", &n) != 1) {
        printf("输入错误：需要一个整数。\n");
        return 1;
    }

    if (n < 0) {
        printf("输入错误：n 不能小于 0。\n");
        return 1;
    }

    printf("1 到 %d 的总和是 %d\n", n, sum_to(n));
    return 0;
}

int main(void)
{
    int choice;

    do {
        show_menu();

        if (scanf("%d", &choice) != 1) {
            printf("输入错误：菜单选项必须是整数。\n");
            return 1;
        }

        switch (choice) {
        case 1:
            print_greeting();
            break;
        case 2:
            if (run_sum_demo() != 0) {
                return 1;
            }
            break;
        case 3:
            printf("提示：比较 for、while 和 do while 的执行顺序。\n");
            break;
        case 0:
            printf("程序结束。\n");
            break;
        default:
            printf("未知选项，请重新选择。\n");
            break;
        }
    } while (/* TODO 2：填写“继续显示菜单”的条件 */);

    return 0;
}

