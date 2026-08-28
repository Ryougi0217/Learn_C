# 第 9 课：extern

## 学习目标

使用 `extern` 声明在其他源文件中定义的外部对象，理解声明与定义的区别。

## 核心概念

- `extern` 声明对象存在，但不在当前文件分配定义存储。
- 一个全局对象应有一个真正定义，其他文件使用 extern 声明。
- 共享可写全局状态会增加耦合，优先考虑通过函数封装。
- 头文件可以集中放外部接口声明。

## 完整示例

下面按文件查看一个完整的最小示例。

### config.h

```c
#ifndef CONFIG_H
#define CONFIG_H

extern int log_level;

#endif
```

### config.c

```c
#include "config.h"

int log_level = 1;
```

### main.c

```c
#include <stdio.h>
#include "config.h"

int main(void)
{
    printf("level=%d\n", log_level);
    log_level = 2;
    printf("level=%d\n", log_level);
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic main.c config.c -o app
./app
```

## 练习任务

1. 完成练习目录中的 extern 声明和唯一的变量定义。
2. 故意在两个源文件都写定义，观察链接器错误。
3. 把可写全局变量改成通过 getter/setter 访问。
4. 解释 `extern` 为什么不是“创建一个新变量”。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

