# 附录第 14 课：缓冲区容量与外部输入

## 学习目标

使用有界输入和长度检查处理外部字符串，避免写入固定数组之外。

## 核心概念

- 固定数组容量必须参与每次写入决策。
- `fgets` 会限制最多读取的字符数量。
- `snprintf` 返回值可以判断结果是否被截断。
- 输入验证应在数据进入核心逻辑前完成。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[8];

    if (fgets(name, sizeof name, stdin) == NULL) {
        return 1;
    }

    char *newline = strchr(name, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    printf("name = %s\n", name);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中使用 `fgets` 读取固定容量的名字。
2. 检查输入是否因为太长而没有读到换行。
3. 使用 `snprintf` 拼接输出，检查返回值。
4. 测试空行、刚好填满和明显超过容量的输入。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

