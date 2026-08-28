# 第 6 课：检查内存申请结果

## 学习目标

把申请失败当成正常控制流处理，练习让函数用返回值报告成功或失败。

## 核心概念

- 任何可能失败的内存申请都要检查。
- 失败路径必须避免解引用 `NULL`。
- 资源申请函数常用“返回指针，失败返回 `NULL`”的接口。
- 调用者要明确知道成功后由谁负责 `free`。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <stdlib.h>

static int *make_int(int value)
{
    int *result = malloc(sizeof *result);

    if (result == NULL) {
        return NULL;
    }

    *result = value;
    return result;
}

int main(void)
{
    int *number = make_int(42);

    if (number == NULL) {
        fputs("could not create number\n", stderr);
        return 1;
    }

    printf("number = %d\n", *number);
    free(number);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的 `make_int`。
2. 让调用者检查返回值后再解引用。
3. 给失败路径写一条输出到 `stderr` 的提示。
4. 在注释中写明成功返回的指针由谁释放。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键挖空。
- [ ] 我测试过至少一个边界或失败情况。

