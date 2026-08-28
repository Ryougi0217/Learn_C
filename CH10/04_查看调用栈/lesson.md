# 第 4 课：查看调用栈

## 学习目标

通过多层函数调用理解调用栈，并定位错误发生在哪一层。

## 核心概念

- 调用栈保存当前函数返回位置和局部状态。
- 每次进入函数通常增加一个栈帧，返回后该帧消失。
- 调试器可以从当前帧切换到调用者帧。
- 调用栈能把“在哪里出错”和“谁调用了它”连接起来。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int level_three(int value)
{
    return value * 2;
}

static int level_two(int value)
{
    return level_three(value + 1);
}

static int level_one(int value)
{
    return level_two(value + 1);
}

int main(void)
{
    printf("result = %d\n", level_one(3));
    return 0;
}
```

## 练习任务

1. 在 `level_three` 中设置断点。
2. 暂停时查看完整调用栈。
3. 切换到上层函数，查看每层的参数。
4. 在一个失败返回路径中重复这个过程，记录调用链。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

