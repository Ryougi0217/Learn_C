# 第 7 课：文件作用域的 static

## 学习目标

使用文件作用域 `static` 隐藏模块内部对象和函数，形成简单的模块边界。

## 核心概念

- 文件作用域的 `static` 符号只在当前源文件可见。
- 其他源文件不能直接访问静态函数或静态全局变量。
- 对外接口放头文件，内部实现细节留在源文件。
- 隐藏内部状态可以降低命名冲突和误用风险。

## 完整示例

### counter.h

```c
#ifndef COUNTER_H
#define COUNTER_H

int counter_next(void);

#endif
```

### counter.c

```c
#include "counter.h"

static int current;

static void increment(void)
{
    current++;
}

int counter_next(void)
{
    increment();
    return current;
}
```

### main.c

```c
#include <stdio.h>
#include "counter.h"

int main(void)
{
    int first = counter_next();
    int second = counter_next();

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

## 练习任务

1. 在练习目录的模块实现中给内部变量和辅助函数加 `static`。
2. 尝试从主文件访问内部变量，解释编译或链接结果。
3. 只通过公开函数改变模块状态。
4. 说明文件作用域 `static` 与函数内部 `static` 的生命周期/可见性区别。

