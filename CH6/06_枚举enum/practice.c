#include <stdio.h>

enum Status
{
    /* TODO：声明 TODO、RUNNING、DONE 三个状态 */
};

static const char *status_name(enum Status status)
{
    switch (status) {
    /* TODO：为每个状态返回字符串 */
    default:
        return "unknown";
    }
}

int main(void)
{
    enum Status status = /* TODO：选择一个状态 */;

    printf("status = %s\n", status_name(status));
    return 0;
}

