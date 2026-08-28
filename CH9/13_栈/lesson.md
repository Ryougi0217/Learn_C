# 第 13 课：栈

## 学习目标

用后进先出规则实现固定容量栈，练习 push、pop 和空/满判断。

## 核心概念

- 栈只在一端进行插入和删除。
- `top` 可以表示下一个空位置。
- `push` 前检查未满，`pop` 前检查非空。
- 栈的典型顺序是 LIFO：最后进入的元素最先出来。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

#define STACK_CAPACITY 4

typedef struct
{
    int values[STACK_CAPACITY];
    size_t top;
} Stack;

static int push(Stack *stack, int value)
{
    if (stack->top == STACK_CAPACITY) {
        return 0;
    }

    stack->values[stack->top++] = value;
    return 1;
}

static int pop(Stack *stack, int *value)
{
    if (stack->top == 0 || value == NULL) {
        return 0;
    }

    *value = stack->values[--stack->top];
    return 1;
}

int main(void)
{
    Stack stack = {0};
    int value;

    push(&stack, 10);
    push(&stack, 20);

    while (pop(&stack, &value)) {
        printf("%d ", value);
    }
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写 `push` 和 `pop`。
2. 测试栈满、栈空和 `value == NULL`。
3. 增加 `peek`，读取栈顶但不删除。
4. 解释为什么 `--top` 要发生在读取数组之前。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

