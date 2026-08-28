# 第 11 课：内存所有权

## 学习目标

建立“谁申请、谁释放”以及“所有权转移”的明确意识，避免多个函数同时释放同一对象。

## 核心概念

- 所有权表示哪个代码路径负责对象的生命周期。
- 返回堆指针时，可以把释放责任转交给调用者。
- 只借用指针的函数不能擅自释放调用者的对象。
- 接口注释应该说明拥有、借用、转移和销毁关系。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

static int *create_owned_value(int value)
{
    int *result = malloc(sizeof *result);

    if (result == NULL) {
        return NULL;
    }

    *result = value;
    return result;  /* 所有权交给调用者 */
}

static void destroy_owned_value(int **value)
{
    if (value != NULL && *value != NULL) {
        free(*value);
        *value = NULL;
    }
}

int main(void)
{
    int *value = create_owned_value(88);

    if (value == NULL) {
        return 1;
    }

    printf("%d\n", *value);
    destroy_owned_value(&value);

    return 0;
}
```

## 练习任务

1. 完成 `create_owned_value` 的申请和初始化。
2. 完成销毁函数，并在释放后把调用者指针置空。
3. 写一段注释说明 `main` 为什么负责调用销毁函数。
4. 设计一个只“借用”指针的打印函数，确认它不调用 `free`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

