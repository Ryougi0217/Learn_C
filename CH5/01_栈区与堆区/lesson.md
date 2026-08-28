# 第 1 课：栈区与堆区

## 学习目标

理解局部变量通常位于栈上，动态申请的对象位于堆上；知道两种存储空间的生命周期不同。

## 核心概念

- 局部变量由进入函数创建，离开作用域后生命周期结束。
- 堆对象由程序显式申请和释放。
- 指针变量保存地址，但不负责自动释放它指向的堆对象。
- 堆内存使用结束后必须调用 `free`。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

static int *make_heap_value(void)
{
    int *value = malloc(sizeof *value);

    if (value == NULL) {
        return NULL;
    }

    *value = 42;
    return value;
}

int main(void)
{
    int stack_value = 7;
    int *heap_value = make_heap_value();

    printf("stack value = %d, address = %p\n",
           stack_value, (void *)&stack_value);

    if (heap_value != NULL) {
        printf("heap value = %d, address = %p\n",
               *heap_value, (void *)heap_value);
        free(heap_value);
        heap_value = NULL;
    }

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中分别打印栈变量和堆变量的值。
2. 观察两者的地址格式，不要根据地址大小判断哪一块“更安全”。
3. 解释为什么函数可以返回堆对象地址，但不应该返回局部变量地址。
4. 为堆申请失败增加清晰的错误提示。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

