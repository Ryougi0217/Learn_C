# 第 16 课：联合体成员共享同一块内存

## 学习目标

通过地址和大小实验，确认联合体成员从同一地址开始，并理解覆盖关系。

## 核心概念

- 联合体对象地址与每个成员地址通常相同。
- 联合体大小至少足够容纳最大的成员，并受对齐影响。
- 写入一个成员会覆盖共享存储中的字节。
- 不要仅凭输出结果推断所有类型重解释都是可移植的。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

union Storage
{
    int number;
    char text[sizeof(int)];
};

int main(void)
{
    union Storage storage = {.number = 0x12345678};

    printf("&storage = %p\n", (void *)&storage);
    printf("&storage.number = %p\n", (void *)&storage.number);
    printf("&storage.text = %p\n", (void *)&storage.text);

    storage.text[0] = 'A';
    printf("text[0] = %c\n", storage.text[0]);

    return 0;
}
```

## 练习任务

1. 填写 `practice.c` 中的联合体成员访问。
2. 打印联合体和两个成员的地址。
3. 写入字符数组后，再观察整数值是否可能变化。
4. 说明为什么字节顺序会影响观察到的整数结果。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我测试过至少一个边界情况。

