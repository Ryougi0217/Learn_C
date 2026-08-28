# 第 10 课：大端序与小端序

## 学习目标

观察多字节整数在内存中的字节排列，并理解字节序转换的必要性。

## 核心概念

- 大端序把高位字节放在低地址。
- 小端序把低位字节放在低地址。
- 用 `unsigned char *` 查看对象表示是合法的字节级观察方式。
- 二进制协议必须明确约定字节序，不能依赖当前机器。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t value = UINT32_C(0x12345678);
    const unsigned char *bytes = (const unsigned char *)&value;

    for (size_t i = 0; i < sizeof value; i++) {
        printf("%02X ", bytes[i]);
    }
    putchar('\n');

    if (bytes[0] == 0x78) {
        puts("little-endian observation");
    } else if (bytes[0] == 0x12) {
        puts("big-endian observation");
    } else {
        puts("other representation");
    }

    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的字节遍历。
2. 运行程序记录当前环境的排列顺序。
3. 设计一个把 `uint32_t` 按大端序写入四个字节的函数。
4. 说明为什么不能把内存中的结构体直接当作可移植文件格式。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

