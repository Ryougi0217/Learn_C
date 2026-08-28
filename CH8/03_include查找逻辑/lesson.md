# 第 3 课：include 查找逻辑

## 学习目标

区分尖括号和双引号包含方式，理解本地头文件、系统头文件和 include 路径。

## 核心概念

- `#include "file.h"` 通常优先查找当前源文件附近的项目头文件。
- `#include <file.h>` 通常查找编译器配置的系统目录。
- `-Ipath` 可以向头文件搜索路径增加项目目录。
- 包含路径错误会在预处理阶段表现为找不到文件。

## 完整示例

下面按文件查看一个完整的最小示例。

### include_demo.h

```c
#ifndef INCLUDE_DEMO_H
#define INCLUDE_DEMO_H

#define DEMO_MESSAGE "local header found"

#endif
```

### main.c

```c
#include <stdio.h>
#include "include_demo.h"

int main(void)
{
    puts(DEMO_MESSAGE);
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic main.c -o app
./app
```

## 练习任务

1. 完成练习目录中的本地头文件。
2. 分别尝试双引号和尖括号，记录查找行为。
3. 把头文件移动到 include 子目录，再用 `-Iinclude` 编译。
4. 解释为什么项目头文件不应依赖系统目录中的同名文件。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

