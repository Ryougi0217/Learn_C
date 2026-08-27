#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned char source[4] = {1, 2, 3, 4};
    unsigned char copy[4];

    /*
     * TODO 1：把 copy 的每个字节清零。
     */
    memset(/* 在这里填写 */, /* 在这里填写 */, /* 在这里填写 */);

    /*
     * TODO 2：把 source 的全部字节复制到 copy。
     */
    memcpy(/* 在这里填写 */, /* 在这里填写 */, /* 在这里填写 */);

    /*
     * TODO 3：比较两个数组的全部字节。
     */
    int same = memcmp(/* 在这里填写 */,
                      /* 在这里填写 */,
                      /* 在这里填写 */) == 0;

    printf("copy: ");
    for (size_t i = 0; i < sizeof copy; i++) {
        printf("%02x ", (unsigned int) copy[i]);
    }
    printf("\n");
    printf("same = %s\n", same ? "yes" : "no");

    return 0;
}


