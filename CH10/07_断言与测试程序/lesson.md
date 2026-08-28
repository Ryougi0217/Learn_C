# 第 7 课：断言与测试程序

## 学习目标

使用 `assert` 表达不变量，并写出能自动判断通过/失败的最小测试。

## 核心概念

- `assert(condition)` 失败时报告文件和行号并终止程序。
- 断言适合检查程序员承诺的不变量。
- 外部输入错误不一定应该用 assert 处理，应返回可处理的错误。
- 测试应有明确输入和预期结果。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <assert.h>
#include <stdio.h>

static int add_ints(int left, int right)
{
    return left + right;
}

static void test_add_ints(void)
{
    assert(add_ints(2, 3) == 5);
    assert(add_ints(-2, 2) == 0);
}

int main(void)
{
    test_add_ints();
    puts("all tests passed");
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中补齐待测函数。
2. 增加负数、零和较大值测试。
3. 故意写错一个预期值，观察断言报告。
4. 说明哪些检查应该返回错误，哪些检查适合 assert。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

