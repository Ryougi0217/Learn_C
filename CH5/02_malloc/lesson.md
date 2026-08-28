# 第 2 课：malloc

## 学习目标

学会使用 `malloc` 申请一块未初始化的堆内存，并在使用前检查返回值。

## 核心概念

- `malloc(bytes)` 返回一块至少包含 `bytes` 个字节的空间。
- 成功时返回可转换为目标指针类型的地址，失败时返回 `NULL`。
- `malloc` 得到的内容没有初始化，不能直接假设它是零。
- 用 `sizeof *pointer` 计算单个对象大小，能减少类型重复。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *score = malloc(sizeof *score);

    if (score == NULL) {
        fputs("malloc failed\n", stderr);
        return 1;
    }

    *score = 95;
    printf("score = %d\n", *score);

    free(score);
    return 0;
}
```

## 练习任务

1. 填写 `practice.c` 中的申请字节数。
2. 运行程序并给申请结果加上 `NULL` 检查。
3. 把 `int` 改成 `double`，观察为什么 `sizeof *pointer` 不需要同步修改。
4. 解释为什么申请成功前不能执行 `*score = 95`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

