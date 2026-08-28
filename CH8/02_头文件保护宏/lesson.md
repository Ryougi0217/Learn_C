# 第 2 课：头文件保护宏

## 学习目标

使用 include guard 防止同一个头文件被重复包含，理解预处理阶段的宏判断。

## 核心概念

- 重复包含可能造成类型或函数声明重复。
- `#ifndef`、`#define`、`#endif` 构成头文件保护宏。
- 保护宏名字应具有项目范围内的唯一性。
- 保护宏只影响预处理文本，不会改变链接阶段的符号。

## 完整示例

### counter.h

```c
#ifndef COUNTER_H
#define COUNTER_H

int next_counter(void);

#endif
```

### counter.c

```c
#include "counter.h"

static int counter;

int next_counter(void)
{
    counter++;
    return counter;
}
```

### main.c

```c
#include <stdio.h>
#include "counter.h"
#include "counter.h"

int main(void)
{
    int first = next_counter();
    int second = next_counter();

    printf("%d %d\n", first, second);
    return 0;
}
```

编译：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic \
    main.c counter.c -o app
./app
```

把两个调用直接写进同一个 `printf` 参数列表会让有副作用的调用顺序不适合作为教学假设，因此这里先保存返回值，再打印。

## 练习任务

1. 在练习目录中补齐保护宏。
2. 保持同一个头文件被包含两次，确认不会报重复定义。
3. 为另一个头文件设计不同的保护宏名字。
4. 为计数器增加重置接口，并思考声明应放在哪里。

