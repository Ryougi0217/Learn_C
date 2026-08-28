# 第 1 课：使用编译器警告定位问题

## 学习目标

把编译器警告当成早期反馈，学会通过更严格的警告选项发现接口和类型问题。

## 核心概念

- `-Wall`、`-Wextra`、`-Wconversion` 能发现许多常见问题。
- 警告不一定意味着程序立即错误，但通常值得解释和处理。
- 不能用强制转换盲目压制未知警告。
- 先读警告定位文件和行，再构造最小修复。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int safe_divide(int left, int right, int *result)
{
    if (right == 0 || result == NULL) {
        return 0;
    }

    *result = left / right;
    return 1;
}

int main(void)
{
    int result;

    if (safe_divide(10, 2, &result)) {
        printf("result = %d\n", result);
    }

    return 0;
}
```

## 练习任务

1. 用严格警告编译完整示例。
2. 在 `practice.c` 的诊断宏中制造未使用变量或隐式转换警告。
3. 记录警告全文，再修复而不是直接关闭选项。
4. 解释 `-Wall` 并不等于“所有警告”。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

