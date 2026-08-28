# 第 6 课：fseek 与 ftell

## 学习目标

在文件流中移动位置并查询当前位置，理解随机访问的基本模型。

## 核心概念

- `fseek` 根据起点和偏移移动文件位置指示器。
- `ftell` 返回当前位置，失败时返回负值。
- `SEEK_SET`、`SEEK_CUR`、`SEEK_END` 表示不同参考点。
- 二进制文件更适合用字节偏移进行定位。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("numbers.bin", "rb");

    if (file == NULL) {
        return 1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return 1;
    }

    long size = ftell(file);
    if (size < 0) {
        fclose(file);
        return 1;
    }

    printf("file size = %ld bytes\n", size);

    if (fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中完成移动到文件末尾的代码。
2. 打印文件大小并回到开头。
3. 用 `SEEK_SET` 跳到第 4 个字节，再记录位置。
4. 解释为什么不能忽略 `fseek` 和 `ftell` 的返回值。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

