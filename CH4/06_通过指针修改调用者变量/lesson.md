# 第 6 课：通过指针修改调用者变量

## 本课目标

完成本课后，你应该能够：

- 解释为什么普通参数修改不会影响调用者变量；
- 通过指针参数修改调用者对象；
- 在修改前检查指针参数；
- 设计“输入地址、写回结果”的简单函数。

## 1. 普通参数修改的是副本

```c
void try_set_zero(int value)
{
    value = 0;
}
```

这个函数改变的是形参副本，调用者的变量不会被直接改写。

## 2. 指针参数可以写回对象

```c
void set_value(int *value, int new_value)
{
    if (value != NULL) {
        *value = new_value;
    }
}
```

调用者传入变量地址：

```c
int score = 95;
set_value(&score, 100);
```

函数通过 `*value` 找到 `score` 并写入新值。

## 3. 完整示例

```c
#include <stdio.h>

void set_value(int *value, int new_value)
{
    if (value != NULL) {
        *value = new_value;
    }
}

int main(void)
{
    int score = 95;

    set_value(&score, 100);
    printf("score = %d\n", score);

    set_value(NULL, 50);
    printf("score after NULL call = %d\n", score);

    return 0;
}
```

传入 `NULL` 时函数不修改任何对象；这是一种由函数自己处理失败输入的设计。

## 修改/实现任务

1. 写出空指针保护；
2. 通过解引用把新值写回调用者变量；
3. 在 `main` 中调用两次，观察 `score`；
4. 增加第二个整数，比较两个地址参数；
5. 解释为什么函数返回后，调用者仍然能看到修改结果。

## 自测题

1. 普通参数为什么不能直接修改调用者变量？
2. 指针参数传递的是什么？
3. `*value = new_value` 修改的是谁？
4. 为什么写入函数仍然要检查 `NULL`？
5. 一个函数通过指针参数返回结果时，调用者需要准备什么？

## 验收标准

- [ ] 能写出带指针参数的修改函数；
- [ ] 能让函数修改调用者变量；
- [ ] 能安全处理 `NULL`；
- [ ] 能解释按值传递和地址传递的差异。

