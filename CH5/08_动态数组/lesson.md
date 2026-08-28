# 第 8 课：动态数组

## 学习目标

使用堆内存保存运行时才知道数量的元素，并用“指针 + count”遍历动态数组。

## 核心概念

- 动态数组没有编译期固定长度。
- 指针只保存首元素地址，元素数量需要单独保存。
- `capacity` 表示已申请的容量，`count` 表示实际使用的元素数。
- 访问下标时必须保证 `index < count`，写入容量内存时必须保证 `index < capacity`。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t capacity = 4;
    size_t count = 0;
    int *values = malloc(capacity * sizeof *values);

    if (values == NULL) {
        return 1;
    }

    values[count++] = 12;
    values[count++] = 25;
    values[count++] = 38;

    for (size_t i = 0; i < count; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
    }

    free(values);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中完成动态数组申请。
2. 让 `count` 从 `0` 开始，并只遍历已经写入的元素。
3. 增加一个元素，但不要超过容量。
4. 解释 `count` 和 `capacity` 不能混为一个变量的原因。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

