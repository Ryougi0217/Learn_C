# 第 11 课：链接多个目标文件

## 学习目标

把多个模块的目标文件链接成一个可执行文件，并理解未定义引用和重复定义。

## 核心概念

- 链接器要为每个外部函数调用找到唯一实现。
- 缺少目标文件会产生 undefined reference。
- 两个目标文件定义同名外部符号会产生重复定义。
- 链接顺序在静态库场景尤其重要，本课先掌握普通目标文件。

## 完整示例

下面按文件查看一个完整的最小示例。

### greet.h

```c
#ifndef GREET_H
#define GREET_H

const char *greeting(void);

#endif
```

### greet.c

```c
#include "greet.h"

const char *greeting(void)
{
    return "hello";
}
```

### math.h

```c
#ifndef MATH_H
#define MATH_H

int triple(int value);

#endif
```

### math.c

```c
#include "math.h"

int triple(int value)
{
    return value * 3;
}
```

### main.c

```c
#include <stdio.h>
#include "greet.h"
#include "math.h"

int main(void)
{
    printf("%s %d\n", greeting(), triple(4));
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic -c greet.c math.c main.c
gcc main.o greet.o math.o -o app
./app
```

## 练习任务

1. 完成练习目录中的两个模块实现。
2. 省略一个目标文件链接，记录错误信息。
3. 在两个源文件中定义同名非 static 函数，观察重复符号错误。
4. 解释头文件声明为什么不能替代源文件实现。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

