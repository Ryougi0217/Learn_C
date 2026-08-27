#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 4;

    /* TODO 1：填写 malloc 的申请表达式。 */
    int *numbers = /* 在这里填写 */;

    if (numbers == NULL) {
        fprintf(stderr, "内存申请失败\n");
        return 1;
    }

    /*
     * 这条边界故意先写成 <=，填完 malloc 后用 Sanitizer 观察越界报告。
     * 修复时应改成只访问 0 到 count - 1。
     */
    for (size_t i = 0; i <= count; i++) {
        numbers[i] = (int) (i * 10);
    }

    for (size_t i = 0; i < count; i++) {
        printf("numbers[%zu] = %d\n", i, numbers[i]);
    }

    /* TODO 2：填写 free 的实参，释放申请的内存。 */
    free(/* 在这里填写 */);

    return 0;
}

