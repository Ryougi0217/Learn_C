# 第 10 课：分别编译多个源文件

## 学习目标

使用 `-c` 把每个源文件分别编译成目标文件，再统一链接。

## 核心概念

- `gcc -c file.c` 只进行预处理、编译和汇编，不执行最终链接。
- 每个目标文件包含本文件需要的符号信息。
- 最终链接阶段把函数调用和实现地址配对。
- 头文件修改后，依赖它的源文件通常需要重新编译。

## 完整示例

下面按文件查看一个完整的最小示例。

### stats.h

```c
#ifndef STATS_H
#define STATS_H

int sum_ints(const int values[], int count);

#endif
```

### stats.c

```c
#include "stats.h"

int sum_ints(const int values[], int count)
{
    int total = 0;

    for (int i = 0; i < count; i++) {
        total += values[i];
    }

    return total;
}
```

### main.c

```c
#include <stdio.h>
#include "stats.h"

int main(void)
{
    int values[] = {2, 4, 6};
    printf("%d\n", sum_ints(values, 3));
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic -c stats.c
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic -c main.c
gcc main.o stats.o -o app
./app
```

## 练习任务

1. 完成练习目录中的统计函数。
2. 分别生成两个 `.o` 文件，再链接。
3. 只修改 `stats.c` 后重新编译它，观察主文件无需改变。
4. 解释为什么 `gcc main.c` 不能找到另一个源文件中的实现。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

