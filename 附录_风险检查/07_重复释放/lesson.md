# 附录第 7 课：重复释放

## 学习目标

识别同一对象被释放两次的路径，并用所有权和置空措施消除风险。

## 核心概念

- 同一动态对象不能被两个所有者各自释放。
- 释放后置空能避免同一个变量再次释放有效旧地址。
- 另一个别名即使没有置空，仍可能保存悬空地址。
- ASan 通常能报告 double free。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);
    if (value == NULL) {
        return 1;
    }

    *value = 3;
    printf("%d\n", *value);

    free(value);
    value = NULL;
    puts("released once");
    return 0;
}
```

## 练习任务

1. 在安全路径中释放并置空。
2. 用一个别名构造诊断用重复释放，使用 ASan 观察。
3. 解释为什么只把一个指针置空不一定能修复别名问题。
4. 设计一个统一销毁函数，集中管理释放责任。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

