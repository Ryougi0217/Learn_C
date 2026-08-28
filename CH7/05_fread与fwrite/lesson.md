# 第 5 课：fread 与 fwrite

## 学习目标

按字节块读写二进制数据，理解返回值表示实际读写的元素数量。

## 核心概念

- `fwrite` 把内存中的元素写入文件。
- `fread` 把文件中的元素读入缓冲区。
- 返回值是成功读写的元素数量，不一定等于请求数量。
- 直接写结构体的二进制布局可能受填充、字节序和类型表示影响。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const uint32_t values[] = {10, 20, 30};
    FILE *file = fopen("numbers.bin", "wb");

    if (file == NULL) {
        return 1;
    }

    size_t count = sizeof values / sizeof values[0];
    if (fwrite(values, sizeof values[0], count, file) != count) {
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        return 1;
    }

    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的 `fwrite` 调用。
2. 再打开文件，用 `fread` 读回数组。
3. 比较请求数量和实际返回数量。
4. 解释为什么二进制文件不能直接假设在所有平台上结构体布局相同。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

