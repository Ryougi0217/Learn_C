#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *duplicate_string(const char *text)
{
    size_t length = /* TODO: 获取 text 长度 */;
    char *copy = /* TODO: 为字符和末尾 \0 申请空间 */;

    if (copy == NULL) {
        return NULL;
    }

    /* TODO: 把 text 和 \0 复制到 copy */
    return copy;
}

int main(void)
{
    char *copy = duplicate_string("heap string");

    if (copy == NULL) {
        return 1;
    }

    printf("%s\n", copy);
    /* TODO: 释放 copy */

    return 0;
}

