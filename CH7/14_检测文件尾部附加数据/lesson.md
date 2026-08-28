# 第 14 课：检测文件尾部附加数据

## 学习目标

根据已知格式长度或结束偏移，判断文件末尾是否存在额外字节。

## 核心概念

- 文件总长度可以通过末尾定位和 `ftell` 获取。
- 已知有效结束位置后，文件总长度更大就说明存在尾部数据。
- “有附加数据”不等于“恶意”，还需要结合格式语义判断。
- 读取和定位失败都不能当作长度为零。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int has_tail(const char *path, long valid_end)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return -1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return -1;
    }

    long file_size = ftell(file);
    fclose(file);

    if (file_size < 0) {
        return -1;
    }

    return file_size > valid_end;
}

int main(void)
{
    int result = has_tail("sample.bin", 8);

    if (result < 0) {
        puts("could not inspect file");
        return 1;
    }

    puts(result ? "extra tail exists" : "no extra tail");
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的末尾定位。
2. 创建一个长度为 8 和长度大于 8 的测试文件。
3. 分别测试空文件和无法打开的文件。
4. 解释为什么要使用 `long` 接收 `ftell` 的结果并检查负值。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

