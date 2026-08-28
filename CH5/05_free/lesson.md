# 第 5 课：free

## 学习目标

掌握释放堆内存的时机，建立“申请一次、释放一次”的基本习惯。

## 核心概念

- `free` 只能释放动态申请且尚未释放的对象。
- 释放后原指针变量仍然保存旧地址，最好立即设为 `NULL`。
- `free(NULL)` 是安全的，但不能因此忽略所有权。
- 释放后不能再读取或写入原对象。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);

    if (value == NULL) {
        return 1;
    }

    *value = 123;
    printf("before free = %d\n", *value);

    free(value);
    value = NULL;

    printf("pointer after free = %s\n",
           value == NULL ? "NULL" : "not NULL");

    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中完成释放和置空。
2. 说明为什么 `free(value); printf("%d", *value);` 是错误的。
3. 把释放操作放进一个函数，保证函数不会再次释放同一对象。
4. 解释为什么设置为 `NULL` 是防误用措施，而不是“恢复内存”。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

