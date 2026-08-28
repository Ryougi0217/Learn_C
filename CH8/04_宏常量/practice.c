#include <stdio.h>

#define MAX_NAME_LENGTH /* TODO：名字容量 */
#define RETRY_LIMIT (/* TODO：重试次数 */)

int main(void)
{
    char name[MAX_NAME_LENGTH] = "Ada";
    int retries = RETRY_LIMIT;

    printf("name=%s retries=%d capacity=%zu\n",
           name, retries, sizeof name);
    return 0;
}

