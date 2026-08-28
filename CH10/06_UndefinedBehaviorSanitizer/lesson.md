# 第 6 课：UndefinedBehaviorSanitizer

## 学习目标

使用 UBSan 观察有符号溢出、除零和非法移位等未定义行为。

## 核心概念

- 未定义行为不是一种固定错误结果。
- UBSan 能在运行时报告许多语言层面的违规操作。
- 诊断前要缩小输入，保证报告容易对应到源代码。
- 修复应改变边界检查或类型设计，而不是只隐藏报告。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <limits.h>
#include <stdio.h>

int main(void)
{
#if defined(UBSAN_DEMO)
    int value = INT_MAX;
    printf("%d\n", value + 1);  /* 诊断用有符号溢出 */
#else
    int value = INT_MAX;
    printf("%d\n", value);
#endif

    return 0;
}
```

## 练习任务

1. 默认编译运行安全分支。
2. 使用 `-fsanitize=undefined` 编译。
3. 加上 `-DUBSAN_DEMO` 运行并记录诊断。
4. 用更宽的类型或边界判断修复溢出。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

