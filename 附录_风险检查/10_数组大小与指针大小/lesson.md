# 附录第 10 课：数组大小与指针大小

## 学习目标

复核数组整体大小、元素大小和指针变量大小的区别。

## 核心概念

- `sizeof array` 在数组作用域内得到整个数组大小。
- `sizeof pointer` 得到指针变量自身大小。
- 数组作为函数参数后通常调整为指针。
- 不能用指针大小推断数组元素数量。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>

int main(void)
{
    int values[4] = {1, 2, 3, 4};
    int *pointer = values;

    printf("array bytes = %zu\n", sizeof values);
    printf("element bytes = %zu\n", sizeof values[0]);
    printf("pointer bytes = %zu\n", sizeof pointer);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中打印三个大小。
2. 验证数组大小除以元素大小得到元素数量。
3. 把数组传进函数，观察参数中的 `sizeof`。
4. 解释为什么函数接口要显式接收 count。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

