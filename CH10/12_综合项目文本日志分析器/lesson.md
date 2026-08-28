# 第 12 课：综合项目 C——文本日志分析器

## 学习目标

逐行读取日志文本，统计 INFO、WARN、ERROR，并为异常输入保留可追踪信息。

## 核心概念

- 日志分析器应按行处理，避免一次性读取整个文件。
- 关键字匹配要明确大小写和边界规则。
- 读取错误、超长行和不存在文件都要有处理策略。
- 统计结果要能回到原始行号验证。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *log =
        "INFO start\n"
        "WARN slow\n"
        "ERROR failed\n"
        "INFO stop\n";
    size_t info = 0;
    size_t warn = 0;
    size_t error = 0;
    char line[64];

    const char *cursor = log;
    while (*cursor != '\0') {
        size_t length = 0;
        while (cursor[length] != '\0'
               && cursor[length] != '\n') {
            length++;
        }

        if (length >= sizeof line) {
            return 1;
        }

        memcpy(line, cursor, length);
        line[length] = '\0';

        if (strncmp(line, "INFO", 4) == 0) {
            info++;
        } else if (strncmp(line, "WARN", 4) == 0) {
            warn++;
        } else if (strncmp(line, "ERROR", 5) == 0) {
            error++;
        }

        cursor += length;
        if (*cursor == '\n') {
            cursor++;
        }
    }

    printf("info=%zu warn=%zu error=%zu\n",
           info, warn, error);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的逐行统计。
2. 把输入改为从文件读取。
3. 记录无法识别的日志行和行号。
4. 测试空文件、超长行、大小写不同和缺少换行的最后一行。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

