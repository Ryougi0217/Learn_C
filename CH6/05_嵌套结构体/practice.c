#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Event
{
    const char *name;
    struct Date date;
};

int main(void)
{
    struct Event event = {
        "release",
        /* TODO：初始化日期 */
    };

    printf("%s: %04d-%02d-%02d\n",
           event.name,
           event.date.year,
           event.date.month,
           event.date.day);
    return 0;
}

