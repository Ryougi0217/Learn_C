# 第 3 课：calloc

## 学习目标

学会使用 `calloc` 申请多个元素，并理解它会把申请到的字节初始化为零。

## 核心概念

- `calloc(count, size)` 申请 `count` 个、每个大小为 `size` 的元素。
- `calloc` 成功后返回的存储空间已经清零。
- 清零不等于所有类型都适合用按位零表示任意语义值；本课先观察整数数组。
- 使用结束后仍然必须 `free`。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t count = 5;
    int *scores = calloc(count, sizeof *scores);

    if (scores == NULL) {
        fputs("calloc failed\n", stderr);
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        printf("scores[%zu] = %d\n", i, scores[i]);
    }

    free(scores);
    return 0;
}
```

## 练习任务

1. 填写 `practice.c` 中的元素数量和单个元素大小。
2. 在循环中给每个元素写入分数，再打印。
3. 把 `calloc` 改成 `malloc`，观察为什么不能再依赖初始值。
4. 说明 `calloc(count, sizeof *scores)` 与数组元素数量的关系。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

