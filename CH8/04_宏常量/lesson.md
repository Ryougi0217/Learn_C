# 第 4 课：宏常量

## 学习目标

使用对象式宏表达编译期常量，并理解宏替换发生在类型检查之前。

## 核心概念

- `#define NAME value` 是预处理替换，不是变量声明。
- 宏常量没有类型和作用域语义，命名通常使用大写。
- 需要类型安全和调试信息时，也可以使用 `const` 对象或枚举。
- 宏值要加括号，避免代入表达式时改变运算优先级。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的练习文件。多文件课程请按照文档列出的编译命令一起编译。

```c
#include <stdio.h>

#define MAX_NAME_LENGTH 32
#define RETRY_LIMIT (3)

int main(void)
{
    char name[MAX_NAME_LENGTH] = "Ada";
    int retries = RETRY_LIMIT;

    printf("name=%s retries=%d\n", name, retries);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中声明名字容量和重试次数宏。
2. 使用宏创建字符数组，并打印容量。
3. 把宏值放进更复杂的算式，观察括号的作用。
4. 解释宏常量和 `const int` 的主要差别。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我知道每个声明、定义和链接符号属于哪个文件。

