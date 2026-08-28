# 第 12 课：内存泄漏

## 学习目标

理解丢失堆对象地址就是泄漏，并使用 Sanitizer 或 LeakSanitizer 发现问题。

## 核心概念

- 申请成功后如果没有对应的 `free`，程序就可能泄漏。
- 把唯一指针改成新地址前，要先处理旧对象。
- 循环中反复申请而不释放，会造成持续增长的泄漏。
- 诊断构建可以帮助定位泄漏，但不能替代所有权设计。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *first = malloc(sizeof *first);
    int *second = malloc(sizeof *second);

    if (first == NULL || second == NULL) {
        free(first);
        free(second);
        return 1;
    }

    *first = 1;
    *second = 2;
    printf("%d %d\n", *first, *second);

    free(first);
    free(second);
    first = NULL;
    second = NULL;

    return 0;
}
```

## 练习任务

1. 运行默认安全路径，确认每次成功申请都有释放。
2. 使用 `LEAK_DEMO` 分支制造一次诊断用泄漏。
3. 用 Sanitizer 或系统工具记录泄漏报告。
4. 解释为什么“程序马上退出”不代表代码没有泄漏。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

