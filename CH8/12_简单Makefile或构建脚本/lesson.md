# 第 12 课：简单 Makefile 或构建脚本

## 学习目标

用 Makefile 描述源文件、目标文件和依赖关系，减少重复输入构建命令。

## 核心概念

- Makefile 的目标描述“如何生成某个文件”。
- 依赖文件更新时间决定是否需要重新构建。
- 头文件出现在依赖列表中，修改头文件时才能正确触发重编译。
- `clean` 通常是伪目标，用于删除构建产物。

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
    return "hello from make";
}
```

### main.c

```c
#include <stdio.h>
#include "greet.h"

int main(void)
{
    puts(greeting());
    return 0;
}
```

### Makefile

```make
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wconversion -pedantic

app: main.o greet.o
	$(CC) $(CFLAGS) main.o greet.o -o app

main.o: main.c greet.h
	$(CC) $(CFLAGS) -c main.c

greet.o: greet.c greet.h
	$(CC) $(CFLAGS) -c greet.c

.PHONY: clean
clean:
	rm -f app main.o greet.o
```

编译命令：

```sh
make
./app
make clean
```

## 练习任务

1. 在练习目录中补齐 Makefile 的编译规则。
2. 增加一个模块，并把它加入链接目标。
3. 修改头文件后运行 `make`，观察哪些文件被重新编译。
4. 解释为什么 `clean` 应该声明为 `.PHONY`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际按多个文件编译过示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我能解释链接器如何找到函数实现。

