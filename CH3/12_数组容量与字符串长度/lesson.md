# 第 12 课：数组容量与字符串长度

## 本课目标

完成本课后，你应该能够：

- 区分数组容量、字符串长度和剩余空间；
- 计算保存额外字符时需要的空间；
- 在写入前检查容量；
- 说明为什么结尾的 `\0` 也要占一个位置。

## 1. 三个不同的量

对于 `char buffer[16]`：

- 容量是 16 个 `char`；
- 字符串长度不超过 15；
- 最后一个位置通常需要保存 `\0`；
- 当前长度会随着内容变化，但容量不会自动变化。

容量是“最多能放多少”，长度是“现在已经放了多少”。

## 2. 添加字符前的检查

如果想在末尾增加一个可见字符，还要为新的 `\0` 留空间：

```c
size_t length = strlen(buffer);

if (length + 1 < sizeof buffer) {
    buffer[length] = '!';
    buffer[length + 1] = '\0';
}
```

条件中的 `+ 1` 同时考虑了新字符和结尾标记：原字符串已经占用 `length` 个可见字符，新增字符放在 `length`，结尾标记放在 `length + 1`。

也可以把条件写成 `length + 2 <= sizeof buffer`，两种写法表达的是同一件事。

## 3. 完整示例

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[16] = "hello";
    size_t capacity = sizeof buffer;
    size_t length = strlen(buffer);

    if (length + 1 < capacity) {
        buffer[length] = '!';
        buffer[length + 1] = '\0';
    }

    printf("buffer = %s\n", buffer);
    printf("length = %zu\n", strlen(buffer));
    printf("capacity = %zu\n", capacity);

    return 0;
}
```

## 常见错误

- 只检查 `length < capacity`，却忘记给 `\0` 留位置；
- 把容量当作当前长度；
- 修改字符串后继续使用旧的长度变量；
- 使用没有容量参数的复制函数处理不可信输入；
- 把字节数、字符数量和用户看到的文字数量混为一谈。

本章只处理普通 ASCII 字符。UTF-8 中文文字可能占用多个字节，不能简单把“字节数”当作“用户看到的字符数”。

## 修改/观察任务

1. 修改缓冲区初始字符串和容量；
2. 让程序在空间足够时追加两个字符；
3. 测试接近容量上限的字符串；
4. 记录追加前后的长度和容量；
5. 把容量判断故意改错，再用 Sanitizer 检查结果。

## 自测题

1. `char buffer[16]` 的容量是多少？
2. 长度为 15 的字符串还需要多少位置保存 `\0`？
3. 为什么添加一个字符时要同时考虑结尾标记？
4. 修改字符串后为什么要重新计算长度？
5. 字节数和用户看到的字符数什么时候可能不同？

## 验收标准

- [ ] 能区分容量和长度；
- [ ] 能在写入前检查剩余空间；
- [ ] 能为新增字符和 `\0` 预留位置；
- [ ] 能说明 ASCII 和多字节文本的边界。

