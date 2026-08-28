# 附录第 12 课：整数溢出

## 学习目标

识别有符号整数溢出风险，并在计算前进行边界检查。

## 核心概念

- 有符号整数溢出是未定义行为。
- 无符号整数溢出按模运算，但仍可能导致业务错误。
- 加法、乘法和容量计算都要考虑上限。
- UBSan 可以帮助发现有符号溢出。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <limits.h>
#include <stdio.h>

static int add_checked(int left, int right, int *result)
{
    if (right > 0 && left > INT_MAX - right) {
        return 0;
    }
    if (right < 0 && left < INT_MIN - right) {
        return 0;
    }

    *result = left + right;
    return 1;
}

int main(void)
{
    int result;

    printf("%d\n", add_checked(INT_MAX, 1, &result));
    printf("%d\n", add_checked(10, 20, &result));
    return 0;
}
```

## 练习任务

1. 完成 `add_checked` 的上下界检查。
2. 用 UBSan 观察不检查版本的有符号溢出。
3. 为乘法设计一个检查函数。
4. 说明为什么动态数组容量翻倍也需要考虑溢出。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

