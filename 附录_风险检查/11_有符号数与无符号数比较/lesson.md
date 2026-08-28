# 附录第 11 课：有符号数与无符号数比较

## 学习目标

避免负数和 `size_t` 比较时发生隐式转换导致的逻辑错误。

## 核心概念

- `size_t` 是无符号类型。
- 负的有符号整数与无符号数比较时可能被转换成很大的无符号数。
- 先检查非负，再显式转换，是常见下标检查写法。
- 严格警告可以帮助发现 signed/unsigned comparison。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>

int main(void)
{
    int index = -1;
    size_t count = 3;

    if (index >= 0 && (size_t)index < count) {
        puts("index is valid");
    } else {
        puts("index is invalid");
    }

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中补齐先判断非负、再转换的条件。
2. 编译直接比较 `index < count` 的版本，记录警告。
3. 测试 `-1`、`0`、`2` 和 `3`。
4. 解释为什么不能只靠强制转换消除所有逻辑问题。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

