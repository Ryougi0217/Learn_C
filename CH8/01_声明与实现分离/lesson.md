# 第 1 课：声明与实现分离

## 学习目标

把函数声明放到头文件，把函数实现放到源文件，让调用者只依赖稳定接口。

## 核心概念

- 头文件通常放类型、宏和函数声明。
- 源文件放函数实现和文件私有辅助函数。
- 调用者只需包含头文件，不需要复制实现。
- 声明和定义的返回类型、参数类型必须一致。

## 完整示例

下面按文件查看一个完整的最小示例。

### math_utils.h

```c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add_ints(int left, int right);

#endif
```

### math_utils.c

```c
#include "math_utils.h"

int add_ints(int left, int right)
{
    return left + right;
}
```

### main.c

```c
#include <stdio.h>
#include "math_utils.h"

int main(void)
{
    printf("%d\n", add_ints(2, 3));
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic main.c math_utils.c -o app
./app
```

## 练习任务

1. 完成练习目录中的头文件声明和源文件实现。
2. 再添加一个 `multiply_ints` 函数。
3. 只在 `math_utils.c` 中保留实现，主文件只包含头文件。
4. 故意改动声明参数，观察编译器如何提示不一致。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

