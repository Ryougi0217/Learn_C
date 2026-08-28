# 第 8 课：动态数组

## 学习目标

把 CH5 的动态内存知识封装成可扩容的整数向量。

## 核心概念

- 向量保存数据指针、实际数量和容量。
- 初始化、追加和销毁是最小生命周期接口。
- 扩容成功后才能更新指针和容量。
- 销毁函数应允许空向量安全调用。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t count;
    size_t capacity;
} IntVector;

static int vector_push(IntVector *vector, int value)
{
    if (vector->count == vector->capacity) {
        size_t new_capacity = vector->capacity == 0
            ? 2 : vector->capacity * 2;
        int *grown = realloc(vector->data,
                              new_capacity * sizeof *grown);

        if (grown == NULL) {
            return 0;
        }

        vector->data = grown;
        vector->capacity = new_capacity;
    }

    vector->data[vector->count++] = value;
    return 1;
}

static void vector_destroy(IntVector *vector)
{
    free(vector->data);
    vector->data = NULL;
    vector->count = 0;
    vector->capacity = 0;
}

int main(void)
{
    IntVector vector = {0};

    for (int i = 1; i <= 5; i++) {
        if (!vector_push(&vector, i * 10)) {
            vector_destroy(&vector);
            return 1;
        }
    }

    for (size_t i = 0; i < vector.count; i++) {
        printf("%d ", vector.data[i]);
    }
    putchar('\n');

    vector_destroy(&vector);
    return 0;
}
```

## 练习任务

1. 手写 `vector_push`。
2. 手写 `vector_destroy`，确保不泄漏。
3. 增加读取指定下标的函数，并检查边界。
4. 测试初始容量为零和连续扩容。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

