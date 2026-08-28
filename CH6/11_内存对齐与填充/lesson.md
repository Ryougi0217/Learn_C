# 第 11 课：内存对齐与填充

## 学习目标

使用 `sizeof` 和 `offsetof` 观察结构体成员之间的填充字节，并理解不能随意假设布局。

## 核心概念

- 编译器可能在成员之间加入填充字节以满足对齐要求。
- 结构体大小通常还要满足整个结构体的对齐要求。
- `offsetof(Type, member)` 可以观察成员相对偏移。
- 不同平台、编译器和成员顺序可能得到不同布局。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stddef.h>
#include <stdio.h>

struct Mixed
{
    char flag;
    int count;
    double ratio;
};

int main(void)
{
    printf("sizeof(struct Mixed) = %zu\n", sizeof(struct Mixed));
    printf("offset flag = %zu\n", offsetof(struct Mixed, flag));
    printf("offset count = %zu\n", offsetof(struct Mixed, count));
    printf("offset ratio = %zu\n", offsetof(struct Mixed, ratio));

    return 0;
}
```

## 练习任务

1. 运行 `practice.c`，记录结构体大小和各成员偏移。
2. 调换成员声明顺序，观察大小是否变化。
3. 增加两个 `char` 成员并重新观察。
4. 解释为什么不能直接把 `sizeof(struct Mixed)` 当作所有成员大小之和。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

