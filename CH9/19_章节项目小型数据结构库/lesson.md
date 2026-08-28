# 第 19 课：章节项目——小型数据结构库

## 学习目标

综合实现一个带初始化、追加、读取和销毁接口的整数向量库。

## 核心概念

- 库接口应隐藏扩容细节，只暴露调用者需要的操作。
- 每个函数都要维护向量不变量：`count <= capacity`。
- 初始化失败时对象仍应处于可销毁状态。
- README 应说明所有权、错误返回值和构建方式。

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

static int vector_init(IntVector *vector)
{
    vector->data = NULL;
    vector->count = 0;
    vector->capacity = 0;
    return 1;
}

static int vector_push(IntVector *vector, int value)
{
    if (vector->count == vector->capacity) {
        size_t new_capacity = vector->capacity == 0
            ? 4 : vector->capacity * 2;
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

static int vector_get(const IntVector *vector,
                      size_t index,
                      int *result)
{
    if (index >= vector->count || result == NULL) {
        return 0;
    }

    *result = vector->data[index];
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
    IntVector vector;
    vector_init(&vector);

    for (int i = 0; i < 5; i++) {
        if (!vector_push(&vector, i * i)) {
            vector_destroy(&vector);
            return 1;
        }
    }

    int value;
    if (vector_get(&vector, 3, &value)) {
        printf("value = %d\n", value);
    }

    vector_destroy(&vector);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的 init、push、get 和 destroy。
2. 增加 pop 操作，处理空向量。
3. 写出至少五个边界测试。
4. 在 README 中写出库的所有权规则和错误返回值。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

