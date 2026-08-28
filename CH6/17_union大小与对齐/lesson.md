# 第 17 课：联合体的大小与对齐

## 学习目标

使用 `sizeof` 观察联合体大小由成员需求和对齐规则共同决定。

## 核心概念

- 联合体大小不是所有成员大小相加。
- 大小至少能容纳最大成员。
- 末尾可能有填充，以满足数组中每个元素的对齐要求。
- 具体结果要以当前目标平台实测为准。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

union Payload
{
    char byte;
    int number;
    double decimal;
    char bytes[16];
};

int main(void)
{
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(union Payload) = %zu\n", sizeof(union Payload));

    return 0;
}
```

## 练习任务

1. 记录每个成员的大小和联合体大小。
2. 增加一个更大的字符数组，观察联合体大小。
3. 解释为什么不能把联合体大小写成成员大小之和。
4. 创建联合体数组，思考末尾对齐对数组步长的影响。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

