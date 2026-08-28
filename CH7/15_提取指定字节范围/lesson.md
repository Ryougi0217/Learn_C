# 第 15 课：提取指定字节范围

## 学习目标

使用 `fseek` 和 `fread` 提取文件中指定偏移和长度的字节，并限制缓冲区容量。

## 核心概念

- 提取前要检查偏移和长度是否在允许范围内。
- 固定缓冲区要求请求长度不超过数组容量。
- `fread` 可能返回少于请求数量，必须报告实际结果。
- 只读提取程序不应修改源文件。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int extract_range(const char *path,
                         long offset,
                         size_t length)
{
    unsigned char buffer[64];

    if (offset < 0 || length > sizeof buffer) {
        return 0;
    }

    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return 0;
    }

    if (fseek(file, offset, SEEK_SET) != 0) {
        fclose(file);
        return 0;
    }

    size_t count = fread(buffer, 1, length, file);
    if (ferror(file)) {
        fclose(file);
        return 0;
    }

    fclose(file);

    for (size_t i = 0; i < count; i++) {
        printf("%02X%s", buffer[i], i + 1 == count ? "" : " ");
    }
    putchar('\n');
    return 1;
}

int main(void)
{
    return extract_range("sample.bin", 0, 16) ? 0 : 1;
}
```

## 练习任务

1. 完成 `practice.c` 中的范围检查、定位和读取。
2. 测试长度为 `0`、超过缓冲区和超过文件末尾的请求。
3. 记录实际提取数量，而不是假定等于请求数量。
4. 思考如果偏移来自命令行，应该增加哪些解析和溢出检查。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

