# 第 11 课：手动实现字符串长度、复制与反转

## 本课目标

完成本课后，你应该能够：

- 不调用字符串库函数，手动扫描字符串；
- 手动复制字符串并保证目标数组结尾有 `\0`；
- 在原数组中反转字符串；
- 在实现函数时同时考虑容量和边界。

## 1. 手动计算长度

字符串长度就是从下标 0 开始，到第一个 `\0` 之前经过的字符数量：

```c
size_t manual_length(const char *text)
{
    size_t length = 0;

    while (text[length] != '\0') {
        length++;
    }

    return length;
}
```

这个函数不计算数组容量，也不包含 `\0`。

## 2. 手动复制

复制时要把可见字符和结尾标记一起写入目标数组。带容量参数的版本可以避免无条件写越界：

```c
void manual_copy(char *destination,
                 size_t capacity,
                 const char *source)
{
    if (capacity == 0) {
        return;
    }

    size_t i = 0;
    while (i + 1 < capacity && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}
```

当源字符串过长时，这个版本会截断，但仍保证目标字符串有结尾标记。

## 3. 手动反转

反转可以交换首尾字符，然后逐步向中间靠拢：

```c
void reverse_in_place(char *text)
{
    size_t length = manual_length(text);

    for (size_t left = 0; left < length / 2; left++) {
        size_t right = length - 1 - left;
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
    }
}
```

空字符串和单字符字符串不需要交换。

## 4. 完整示例

```c
#include <stdio.h>

size_t manual_length(const char *text)
{
    size_t length = 0;

    while (text[length] != '\0') {
        length++;
    }

    return length;
}

void manual_copy(char *destination,
                 size_t capacity,
                 const char *source)
{
    if (capacity == 0) {
        return;
    }

    size_t i = 0;
    while (i + 1 < capacity && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}

void reverse_in_place(char *text)
{
    size_t length = manual_length(text);

    for (size_t left = 0; left < length / 2; left++) {
        size_t right = length - 1 - left;
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
    }
}

int main(void)
{
    char source[] = "Bootdev";
    char copied[32];

    manual_copy(copied, sizeof copied, source);

    printf("source length = %zu\n", manual_length(source));
    printf("copied = %s\n", copied);

    reverse_in_place(copied);
    printf("reversed = %s\n", copied);

    return 0;
}
```

## 实现任务

1. 手写 `manual_length`；
2. 手写带容量限制的 `manual_copy`；
3. 手写原地反转函数；
4. 测试空字符串、单字符、偶数长度和奇数长度；
5. 测试目标数组比源字符串短的情况；
6. 说明每个函数如何保证不越过 `\0` 或目标容量。

## 自测题

1. 手动长度函数为什么在遇到 `\0` 时停止？
2. 复制字符串时为什么必须复制结尾标记？
3. 容量为 0 时，复制函数应该做什么？
4. 反转字符串时为什么只需要循环到长度的一半？
5. 截断复制和越界复制有什么区别？

## 验收标准

- [ ] 能手写字符串长度函数；
- [ ] 能手写带容量限制的复制函数；
- [ ] 能手写原地反转函数；
- [ ] 能处理空字符串和短目标数组；
- [ ] 能解释每个边界条件。

