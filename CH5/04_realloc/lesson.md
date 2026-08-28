# 第 4 课：realloc

## 学习目标

理解 `realloc` 如何调整堆空间大小，以及为什么需要先用临时指针接收结果。

## 核心概念

- `realloc(pointer, new_size)` 尝试调整原对象大小。
- 成功时可能返回新地址，旧指针不能继续当作当前对象地址使用。
- 失败时返回 `NULL`，原来的对象仍然有效。
- 直接把结果写回唯一指针可能丢失原地址；先保存到临时指针更安全。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 2;
    int *values = malloc(count * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    values[0] = 10;
    values[1] = 20;

    size_t new_count = 4;
    int *grown = realloc(values, new_count * sizeof *values);

    if (grown == NULL) {
        free(values);
        return 1;
    }

    values = grown;
    values[2] = 30;
    values[3] = 40;

    for (size_t i = 0; i < new_count; i++) {
        printf("%d\n", values[i]);
    }

    free(values);
    return 0;
}
```

## 练习任务

1. 填写 `practice.c` 中的 `realloc` 调用。
2. 保留临时指针，不要直接覆盖唯一的旧指针。
3. 模拟申请失败的处理流程：失败时释放旧空间并返回错误。
4. 解释 `realloc` 成功后为什么要让 `values = grown`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

