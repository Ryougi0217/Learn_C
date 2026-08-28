# 附录第 5 课：返回局部变量地址

## 学习目标

识别函数返回局部变量地址的生命周期错误，并改成按值返回或输出参数。

## 核心概念

- 局部变量离开函数后生命周期结束。
- 返回局部变量地址会产生悬空指针。
- 按值返回小型结果，或让调用者提供输出空间，都是常见替代方案。
- 编译器通常可以对返回局部地址发出警告。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>
#include <stddef.h>

static int make_value(int *destination)
{
    if (destination == NULL) {
        return 0;
    }

    *destination = 42;
    return 1;
}

int main(void)
{
    int result = 0;

    if (make_value(&result)) {
        printf("%d\n", result);
    }
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中完成输出参数版本。
2. 用按值返回整数的版本与输出参数比较。
3. 只在诊断宏中保留返回局部地址的错误代码。
4. 记录编译器警告并解释生命周期结束的时刻。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

