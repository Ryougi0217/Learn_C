# 第 9 课：固定宽度整数类型

## 学习目标

使用 `stdint.h` 中的固定宽度整数描述二进制格式，使用 `inttypes.h` 正确打印。

## 核心概念

- `uint8_t`、`uint16_t`、`uint32_t` 等类型表达位宽意图。
- 固定宽度类型可能在平台上不存在，因此代码应使用标准头文件提供的定义。
- `PRIu32` 等宏用于匹配格式说明符。
- 固定宽度不自动解决字节序和文件格式兼容问题。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t magic = UINT32_C(0x12345678);
    int16_t offset = -12;

    printf("magic = 0x%" PRIX32 "\n", magic);
    printf("offset = %" PRId16 "\n", offset);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中声明 `uint32_t` 和 `int16_t`。
2. 使用对应的打印宏，而不是猜测 `%d` 或 `%u`。
3. 把这些值写入二进制文件并读回。
4. 说明固定宽度类型和固定字节序是两个不同问题。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

