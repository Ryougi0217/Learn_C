# 第 10 课：传值与传指针

## 学习目标

通过同一个结构体比较按值传递和指针传递对调用者对象的影响。

## 核心概念

- 按值传递只修改函数内部的副本。
- 传递指针可以修改调用者拥有的对象。
- 只读指针和可写指针表达不同权限。
- 选择接口时要明确函数是否需要改变对象。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

typedef struct
{
    int score;
} Result;

static void add_by_value(Result result)
{
    result.score += 10;
}

static void add_by_pointer(Result *result)
{
    if (result != NULL) {
        result->score += 10;
    }
}

int main(void)
{
    Result result = {70};

    add_by_value(result);
    printf("after value = %d\n", result.score);

    add_by_pointer(&result);
    printf("after pointer = %d\n", result.score);

    return 0;
}
```

## 练习任务

1. 完成两个函数的分数修改。
2. 在调用前后分别打印结果。
3. 解释为什么第一次调用没有改变 `main` 中的变量。
4. 为指针版本增加 `NULL` 保护。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

