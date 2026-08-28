# 附录第 13 课：输入与文件返回值检查

## 学习目标

把 `fgets`、字符串转换和 `fopen` 的失败都作为正常控制流处理。

## 核心概念

- 外部输入永远不能假定格式正确。
- `fgets` 返回 `NULL` 时要区分 EOF 和读取错误。
- 数字转换要检查尾部字符、范围和 errno。
- 文件打开失败时不能继续读写空流指针。

## 完整示例

先阅读并运行默认安全路径，再打开同目录的 `practice.c` 完成练习。带宏的危险路径只用于诊断。

```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char line[32];

    if (fgets(line, sizeof line, stdin) == NULL) {
        if (ferror(stdin)) {
            perror("stdin");
        }
        return 1;
    }

    char *end;
    errno = 0;
    long value = strtol(line, &end, 10);

    if (errno != 0 || end == line) {
        puts("invalid number");
        return 1;
    }

    printf("value = %ld\n", value);
    return 0;
}
```

## 练习任务

1. 在 `practice.c` 中检查 `fgets` 返回值。
2. 补齐数字转换失败、尾部字符和范围检查。
3. 给文件打开增加错误输出。
4. 测试空输入、字母、超长数字和正常数字。

## 本课检查点

- [ ] 我能说明本课风险的触发条件。
- [ ] 我实际运行过默认安全路径。
- [ ] 我手写或修复过关键检查。
- [ ] 我知道如何用编译器警告或 Sanitizer 验证结果。

