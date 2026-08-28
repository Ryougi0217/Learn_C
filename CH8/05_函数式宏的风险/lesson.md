# 第 5 课：函数式宏的风险

## 学习目标

观察函数式宏的重复求值和优先级风险，并学会在适合时使用真正的函数。

## 核心概念

- 函数式宏只是文本替换，不会自动保证参数只求值一次。
- 宏参数和整个结果都应该考虑括号。
- `SQUARE(i++)` 可能多次修改参数，产生未定义行为。
- 对普通计算优先使用类型明确的函数或 inline 函数。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的练习文件。多文件课程请按照文档列出的编译命令一起编译。

```c
#include <stdio.h>

#define BAD_SQUARE(x) x * x
#define SQUARE(x) ((x) * (x))

static int square_int(int value)
{
    return value * value;
}

int main(void)
{
    printf("bad precedence = %d\n", 2 + BAD_SQUARE(3));
    printf("safe macro = %d\n", 2 + SQUARE(3));
    printf("function = %d\n", square_int(3));
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中分别写出有括号和无括号的平方宏。
2. 预测 `2 + BAD_SQUARE(3)` 的结果并运行验证。
3. 不要把 `i++` 作为宏参数，解释原因。
4. 把宏替换为函数，比较可读性和类型检查。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习文件中的关键部分。
- [ ] 我知道每个声明、定义和链接符号属于哪个文件。

