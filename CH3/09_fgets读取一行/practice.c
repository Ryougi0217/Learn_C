#include <stdio.h>

int main(void)
{
    char line[64];

    printf("请输入一行文字：");

    /*
     * TODO 1：填写 fgets 的三个参数：
     * 目标数组、数组容量和标准输入流。
     */
    if (fgets(/* 在这里填写 */,
             /* 在这里填写 */,
             /* 在这里填写 */) == NULL) {
        fprintf(stderr, "没有读到输入。\n");
        return 1;
    }

    printf("原始输入：[%s]", line);
    return 0;
}

