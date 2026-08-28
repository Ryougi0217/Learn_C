# 第 9 课：动态数组扩容

## 学习目标

手写一个会自动扩容的整数数组，练习二级指针、临时指针和容量管理。

## 核心概念

- 扩容函数需要修改调用者保存的首地址，因此参数常是 `int **`。
- 容量不足时先计算新容量，再用临时指针调用 `realloc`。
- 只有申请成功后，才能更新首地址和容量。
- 扩容失败时，旧数组仍然应该保持有效。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

static int append_value(int **values,
                        size_t *count,
                        size_t *capacity,
                        int value)
{
    if (*count == *capacity) {
        size_t new_capacity = *capacity * 2;
        int *grown = realloc(*values,
                              new_capacity * sizeof **values);

        if (grown == NULL) {
            return 0;
        }

        *values = grown;
        *capacity = new_capacity;
    }

    (*values)[*count] = value;
    (*count)++;
    return 1;
}

int main(void)
{
    size_t count = 0;
    size_t capacity = 2;
    int *values = malloc(capacity * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    for (int value = 10; value <= 50; value += 10) {
        if (!append_value(&values, &count, &capacity, value)) {
            free(values);
            return 1;
        }
    }

    for (size_t i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');

    free(values);
    return 0;
}
```

## 练习任务

1. 完成 `append_value` 中的容量判断。
2. 填写安全的 `realloc` 临时指针。
3. 成功后更新 `*values`、`*capacity` 和 `*count`。
4. 测试初始容量为 `1`、连续添加至少 `8` 个元素的情况。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

