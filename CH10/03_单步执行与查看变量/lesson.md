# 第 3 课：单步执行与查看变量

## 学习目标

使用单步、步入和步过观察函数参数、局部变量及返回值的变化。

## 核心概念

- step over 执行当前行但不进入被调用函数。
- step into 进入函数内部查看参数和局部状态。
- 观察变量时要注意当前作用域和生命周期。
- 调试输出应帮助验证假设，而不是替代理解代码。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static void add_points(int *score, int points)
{
    if (score != NULL) {
        *score += points;
    }
}

int main(void)
{
    int score = 70;

    add_points(&score, 5);
    printf("score = %d\n", score);
    return 0;
}
```

## 练习任务

1. 在 `add_points` 入口和解引用前设置断点。
2. 单步观察 `score`、`points` 和 `*score`。
3. 传入空指针，观察哪个分支执行。
4. 解释为什么查看变量必须结合当前栈帧。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

