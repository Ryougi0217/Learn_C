# 附录第 4 课：空指针解引用

## 学习目标

在使用指针前检查是否为空，并区分空指针错误和悬空指针错误。

## 核心概念

- `NULL` 表示不指向任何对象。
- 对 `NULL` 解引用会产生未定义行为，常见结果是崩溃。
- 空检查是必要条件，但不是证明对象生命周期有效的充分条件。
- 接口可以用返回值报告空参数错误。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>
#include <stddef.h>

static int read_value(const int *pointer, int *result)
{
    if (pointer == NULL || result == NULL) {
        return 0;
    }

    *result = *pointer;
    return 1;
}

int main(void)
{
    int value = 7;
    int result;

    printf("%d\n", read_value(&value, &result));
    printf("result = %d\n", result);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 的空指针检查。
2. 测试两个参数分别为空的情况。
3. 添加诊断宏后用 UBSan 观察空指针解引用。
4. 说明空指针和悬空指针为什么不能混为一谈。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

