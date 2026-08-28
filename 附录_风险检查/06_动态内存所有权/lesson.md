# 附录第 6 课：动态内存所有权

## 学习目标

在动态对象的创建、借用、转移和销毁之间建立明确的所有权规则。

## 核心概念

- 成功申请的内存必须有明确的释放者。
- 借用函数不应释放不属于自己的对象。
- 所有权转移后，原持有者不应继续使用或释放对象。
- 销毁接口可以在释放后把指针置空。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>
#include <stdlib.h>

static int *create_value(int value)
{
    int *result = malloc(sizeof *result);
    if (result == NULL) {
        return NULL;
    }

    *result = value;
    return result;
}

static void destroy_value(int **value)
{
    if (value != NULL) {
        free(*value);
        *value = NULL;
    }
}

int main(void)
{
    int *value = create_value(9);
    if (value == NULL) {
        return 1;
    }

    printf("%d\n", *value);
    destroy_value(&value);
    return 0;
}
```

## 练习任务

1. 完成创建函数和销毁函数。
2. 给接口注释标注 owner 和 borrowed。
3. 测试销毁空指针和销毁后再次调用。
4. 用 LeakSanitizer 检查所有路径。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

