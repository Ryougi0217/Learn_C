# 第 13 课：多文件构建与 README

## 学习目标

把一个综合项目拆成多个源文件，提供可复现构建命令和项目说明。

## 核心概念

- 头文件只暴露稳定接口，模块内部辅助函数使用 `static`。
- 调试构建和发布构建可以使用不同编译选项。
- README 要写清构建、运行、测试和限制。
- 综合项目结束前要能从干净目录重新构建。

## 完整示例

下面按文件查看一个完整的最小项目。

### report.h

```c
#ifndef REPORT_H
#define REPORT_H

int report_score(int value);

#endif
```

### report.c

```c
#include "report.h"

int report_score(int value)
{
    return value >= 60;
}
```

### main.c

```c
#include <stdio.h>
#include "report.h"

int main(void)
{
    printf("%s\n", report_score(88) ? "pass" : "fail");
    return 0;
}
```

编译命令：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic -g -O0 \
    main.c report.c -o app
./app
```

## 练习任务

1. 把练习项目拆成头文件、实现文件和主文件。
2. 写出 debug 和 release 两套构建命令。
3. 编写 README，说明输入、输出、测试和限制。
4. 删除可执行文件和目标文件后，从零构建一次。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

