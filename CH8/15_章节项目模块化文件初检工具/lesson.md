# 第 15 课：章节项目——模块化文件初检工具

## 学习目标

把文件大小、头部读取和格式识别拆成模块，完成一个可独立构建的只读工具。

## 核心概念

- 公共头文件只暴露主程序需要的函数。
- 文件扫描模块负责打开、读取和识别，主程序负责参数和输出。
- 模块内部辅助函数使用文件作用域 `static`。
- 项目需要同时编译多个源文件，并提供 README 或 Makefile。

## 完整示例

下面按文件查看一个完整的最小示例。

### include/file_scan.h

```c
#ifndef FILE_SCAN_H
#define FILE_SCAN_H

#include <stddef.h>

long scan_file_size(const char *path);
const char *scan_format(const unsigned char *header, size_t count);

#endif
```

### src/file_scan.c

```c
#include "file_scan.h"
#include <stdio.h>
#include <string.h>

long scan_file_size(const char *path)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return -1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return -1;
    }

    long size = ftell(file);
    fclose(file);
    return size;
}

const char *scan_format(const unsigned char *header, size_t count)
{
    if (count >= 4 && memcmp(header, "%PDF", 4) == 0) {
        return "PDF";
    }
    return "unknown";
}
```

### src/main.c

```c
#include <stdio.h>
#include "file_scan.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    long size = scan_file_size(argv[1]);
    if (size < 0) {
        return 1;
    }

    printf("size = %ld\n", size);
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic -Iinclude \
    src/main.c src/file_scan.c -o file_scan
./file_scan sample.bin
```

## 练习任务

1. 完成练习目录中的头文件和扫描模块。
2. 让主程序真正读取头部并调用格式识别函数。
3. 增加 ELF、PNG 或 GIF 判断。
4. 为项目补写 README，列出构建命令和只读限制。
5. 用 `nm` 或链接错误信息确认模块之间的符号关系。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

