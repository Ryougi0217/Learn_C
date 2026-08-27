#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *source = "array";
    const char *other = "arrays";
    char copied[32];

    /*
     * TODO 1：填写 strlen 的实参。
     */
    size_t length = strlen(/* 在这里填写 */);

    /*
     * TODO 2：填写 strcmp 的两个实参。
     */
    int comparison = strcmp(/* 在这里填写 */, /* 在这里填写 */);

    /*
     * TODO 3：填写 strcpy 的目标数组和源字符串。
     */
    strcpy(/* 在这里填写 */, /* 在这里填写 */);

    printf("source = %s\n", source);
    printf("length = %zu\n", length);
    printf("comparison = %d\n", comparison);
    printf("copied = %s\n", copied);

    return 0;
}

