# 附录第 8 课：释放后使用

## 学习目标

识别释放后仍通过原指针或别名访问对象的错误。

## 核心概念

- `free` 后对象生命周期结束，所有指向它的别名都不能再解引用。
- 把一个变量设为 `NULL` 不会自动清理其他别名。
- 释放后使用可能读取旧值，也可能立即崩溃。
- ASan 对这类错误通常能给出访问栈和释放栈。

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

    *value = 12;
    printf("before free = %d\n", *value);

    free(value);
    value = NULL;
    puts("safe after free");
    return 0;
}
```

## 练习任务

1. 完成安全释放路径。
2. 保存一个别名后释放，再只在诊断宏中解引用别名。
3. 使用 ASan 记录错误位置。
4. 解释为什么“打印旧值”不是释放后使用正确的证据。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

