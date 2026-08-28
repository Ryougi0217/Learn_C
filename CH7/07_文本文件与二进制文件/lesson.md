# 第 7 课：文本文件与二进制文件

## 学习目标

比较文本和二进制数据的表示、可读性、换行处理和可移植性。

## 核心概念

- 文本文件面向字符和行，适合配置、日志和人工查看。
- 二进制文件保存原始字节，通常更紧凑、读取结构固定。
- 文本模式在某些平台可能转换换行符。
- 二进制格式需要自己定义字段大小、字节序和版本规则。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    const unsigned char bytes[] = {0x41, 0x00, 0x42, 0xff};
    unsigned char loaded[sizeof bytes];

    FILE *file = fopen("sample.bin", "wb");
    if (file == NULL) {
        return 1;
    }

    if (fwrite(bytes, 1, sizeof bytes, file) != sizeof bytes) {
        fclose(file);
        return 1;
    }
    fclose(file);

    file = fopen("sample.bin", "rb");
    if (file == NULL) {
        return 1;
    }

    size_t read_count = fread(loaded, 1, sizeof loaded, file);
    fclose(file);

    for (size_t i = 0; i < read_count; i++) {
        printf("%02X ", loaded[i]);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 分别用文本模式和二进制模式打开测试文件。
2. 写入包含 `0x00` 的字节数组，观察文本工具能否完整显示。
3. 说明为什么二进制读取不应使用字符串函数。
4. 设计一个包含魔数、版本和长度的简单二进制文件头。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

