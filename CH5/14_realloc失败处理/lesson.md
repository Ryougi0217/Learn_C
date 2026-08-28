# 第 14 课：realloc 失败处理

## 学习目标

综合使用临时指针、容量检查和失败回滚，写出不会丢失旧对象的扩容函数。

## 核心概念

- `realloc` 失败时，旧内存仍然属于调用者。
- 不要把 `realloc` 结果直接覆盖唯一旧指针。
- 新容量计算也可能溢出，应在乘法前检查上限。
- 失败路径必须让调用者仍能释放旧数组。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

static int resize_values(int **values,
                          size_t old_count,
                          size_t new_count)
{
    (void)old_count;

    if (new_count > SIZE_MAX / sizeof **values) {
        return 0;
    }

    int *grown = realloc(*values, new_count * sizeof **values);

    if (grown == NULL && new_count != 0) {
        return 0;
    }

    *values = grown;
    return 1;
}

int main(void)
{
    size_t count = 2;
    int *values = malloc(count * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    values[0] = 10;
    values[1] = 20;

    if (!resize_values(&values, count, 4)) {
        free(values);
        return 1;
    }

    values[2] = 30;
    values[3] = 40;

    for (size_t i = 0; i < 4; i++) {
        printf("%d ", values[i]);
    }
    putchar('\n');

    free(values);
    return 0;
}
```

## 练习任务

1. 完成 `resize_values` 的溢出判断、`realloc` 和回写。
2. 思考 `new_count == 0` 时是否需要把指针置空。
3. 解释失败返回时为什么不能把 `*values` 改成 `NULL`。
4. 在注释中写出调用者的清理责任。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

