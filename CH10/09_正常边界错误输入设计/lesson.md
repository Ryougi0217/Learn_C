# 第 9 课：正常、边界与错误输入设计

## 学习目标

按输入分类设计测试矩阵，而不是只验证一条正常路径。

## 核心概念

- 正常输入验证主要功能。
- 边界输入验证最小值、最大值、空值和容量边缘。
- 错误输入验证格式、权限、缺失参数和非法范围。
- 测试用例应可重复、可命名并能定位失败。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int is_valid_score(int score)
{
    return score >= 0 && score <= 100;
}

struct TestCase
{
    const char *name;
    int input;
    int expected;
};

int main(void)
{
    const struct TestCase cases[] = {
        {"zero", 0, 1},
        {"middle", 50, 1},
        {"max", 100, 1},
        {"below", -1, 0},
        {"above", 101, 0}
    };

    size_t count = sizeof cases / sizeof cases[0];
    size_t failures = 0;

    for (size_t i = 0; i < count; i++) {
        int actual = is_valid_score(cases[i].input);
        if (actual != cases[i].expected) {
            printf("FAIL %s\n", cases[i].name);
            failures++;
        }
    }

    printf("failures = %zu\n", failures);
    return failures == 0 ? 0 : 1;
}
```

## 练习任务

1. 在 `practice.c` 中增加空输入、最大长度和非法字符测试。
2. 把测试结果改成返回非零失败码。
3. 每个失败用例打印名字、输入、预期和实际。
4. 解释为什么边界测试通常比随机打印更有信息量。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

