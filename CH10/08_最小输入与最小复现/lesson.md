# 第 8 课：最小输入与最小复现

## 学习目标

把复杂失败缩小成最短输入和最少代码，让问题容易观察和修复。

## 核心概念

- 最小复现应保留触发问题所需的最少条件。
- 输入、环境、编译选项和实际输出都要记录。
- 解析函数应检查空字符串、非法字符和范围。
- 复现成功后，先写测试固定问题，再修改实现。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_score(const char *text, int *score)
{
    if (text == NULL || score == NULL || *text == '\0') {
        return 0;
    }

    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);

    if (errno != 0 || *end != '\0'
        || value < 0 || value > 100) {
        return 0;
    }

    *score = (int)value;
    return 1;
}

int main(void)
{
    int score;

    printf("%d\n", parse_score("99", &score));
    printf("%d\n", parse_score("101", &score));
    return 0;
}
```

## 练习任务

1. 选择一个已有错误，缩小到一个输入。
2. 完成 `parse_score` 的空输入和范围检查。
3. 测试 `""`、`"0"`、`"100"`、`"101"` 和 `"x"`。
4. 记录编译命令、输入、输出和修复前后差异。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

