# 第 15 课：章节项目——动态成绩管理程序

## 项目目标

使用动态数组保存运行时数量的成绩，完成追加、扩容、最大值和平均值统计，同时正确处理空数组和申请失败。

## 核心概念

- 程序用 `int *scores` 保存成绩，用 `count` 和 `capacity` 管理数组。
- 追加函数需要二级指针，因为扩容可能改变首地址。
- 项目要求所有成功申请都有对应释放。
- 平均值计算时要显式转换，避免整数除法丢失小数。
- 空数组不能读取第一个元素，也不能直接做除法。

## 完整参考实现

```c
#include <stdio.h>
#include <stdlib.h>

static int append_score(int **scores,
                        size_t *count,
                        size_t *capacity,
                        int score)
{
    if (*count == *capacity) {
        size_t new_capacity = *capacity * 2;
        int *grown = realloc(*scores,
                              new_capacity * sizeof **scores);

        if (grown == NULL) {
            return 0;
        }

        *scores = grown;
        *capacity = new_capacity;
    }

    (*scores)[*count] = score;
    (*count)++;
    return 1;
}

static int max_score(const int *scores, size_t count)
{
    if (count == 0) {
        return 0;
    }

    int maximum = scores[0];

    for (size_t i = 1; i < count; i++) {
        if (scores[i] > maximum) {
            maximum = scores[i];
        }
    }

    return maximum;
}

static double average_score(const int *scores, size_t count)
{
    if (count == 0) {
        return 0.0;
    }

    int total = 0;

    for (size_t i = 0; i < count; i++) {
        total += scores[i];
    }

    return (double)total / (double)count;
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

    printf("empty max = %d\n", max_score(NULL, 0));
    printf("empty average = %.2f\n", average_score(NULL, 0));

    free(scores);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的 `append_score`。
2. 手写最大值函数和平均值函数，并处理 `count == 0`。
3. 增加输入成绩范围检查，只接受 `0～100`。
4. 测试空数组、只有一个成绩、需要多次扩容的情况。
5. 在项目结束前列出每一块堆内存的释放位置。

## 本课检查点

- [ ] 我能维护 `count <= capacity`。
- [ ] 我能安全处理扩容失败。
- [ ] 我不会对空数组取第一个元素或除以零。
- [ ] 我实际手写并测试了三个核心函数。

