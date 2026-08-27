#include <stdio.h>

int total_visits = 0;

void record_visit(void)
{
    int local_number = 100;

    total_visits++;
    printf("函数内部：local_number=%d, total_visits=%d\n",
           local_number, total_visits);
}

int main(void)
{
    int outer_number = 10;

    record_visit();

    {
        int inner_number = 20;
        printf("代码块内部：outer=%d, inner=%d\n",
               outer_number, inner_number);
    }

    printf("代码块外部：outer=%d, total=%d\n",
           outer_number, total_visits);
    return 0;
}

