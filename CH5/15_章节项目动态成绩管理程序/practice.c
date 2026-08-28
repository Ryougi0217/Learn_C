#include <stdio.h>
#include <stdlib.h>

static int append_score(int **scores,
                        size_t *count,
                        size_t *capacity,
                        int score)
{
    if (/* TODO: 容量已满 */) {
        size_t new_capacity = /* TODO: 扩大容量 */;
        int *grown = /* TODO: 安全扩容 */;

        if (/* TODO: 判断失败 */) {
            return 0;
        }

        *scores = grown;
        *capacity = new_capacity;
    }

    /* TODO: 保存 score 并更新 count */
    return 1;
}

static int max_score(const int *scores, size_t count)
{
    if (/* TODO: 空数组 */) {
        return 0;
    }

    int maximum = /* TODO: 用第一个元素初始化 */;

    for (size_t i = 1; i < count; i++) {
        /* TODO: 更新最大值 */
    }

    return maximum;
}

static double average_score(const int *scores, size_t count)
{
    if (/* TODO: 空数组 */) {
        return 0.0;
    }

    int total = 0;

    for (size_t i = 0; i < count; i++) {
        /* TODO: 累加 scores[i] */
    }

    return /* TODO: 转换后计算平均值 */;
}

int main(void)
{
    const int input[] = {78, 91, 66, 84, 95};
    size_t count = 0;
    size_t capacity = 2;
    int *scores = malloc(capacity * sizeof *scores);

    if (scores == NULL) {
        return 1;
    }

    for (size_t i = 0; i < sizeof input / sizeof input[0]; i++) {
        if (!append_score(&scores, &count, &capacity, input[i])) {
            free(scores);
            return 1;
        }
    }

    printf("count = %zu\n", count);
    printf("max = %d\n", max_score(scores, count));
    printf("average = %.2f\n", average_score(scores, count));

    free(scores);
    return 0;
}

