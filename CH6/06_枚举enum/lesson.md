# 第 6 课：枚举 enum

## 学习目标

用枚举表示有限的命名状态，避免用难以理解的魔法数字。

## 核心概念

- `enum` 为整数常量提供可读名字。
- 枚举变量适合表示状态、类别和模式。
- 枚举常量默认从 `0` 开始递增，也可以显式指定值。
- 仍然要注意外部整数转换可能带来无效状态。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

enum Status
{
    STATUS_TODO,
    STATUS_RUNNING,
    STATUS_DONE
};

static const char *status_name(enum Status status)
{
    switch (status) {
    case STATUS_TODO:
        return "todo";
    case STATUS_RUNNING:
        return "running";
    case STATUS_DONE:
        return "done";
    default:
        return "unknown";
    }
}

int main(void)
{
    enum Status status = STATUS_RUNNING;

    printf("status = %s\n", status_name(status));
    return 0;
}
```

## 练习任务

1. 补齐 `practice.c` 中的枚举声明。
2. 写一个函数把状态转换为字符串。
3. 增加 `STATUS_FAILED`。
4. 解释为什么使用状态名比直接写 `1`、`2` 更容易维护。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

