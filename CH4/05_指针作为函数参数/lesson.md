# 第 5 课：指针作为函数参数

## 本课目标

完成本课后，你应该能够：

- 把对象地址作为函数实参传入；
- 写出接收指针参数的函数；
- 在函数内部通过解引用读取调用者对象；
- 说明普通参数和指针参数的差异。

## 1. 传值和传地址

普通参数接收实参的值副本：

```c
void print_copy(int value)
{
    printf("%d\n", value);
}
```

指针参数接收一个地址，可以访问地址对应的对象：

```c
void print_pointed_value(const int *value)
{
    printf("%d\n", *value);
}
```

调用时传入 `&score`：

```c
int score = 95;
print_pointed_value(&score);
```

当前先关注读取；下一课会用指针参数修改调用者变量。

## 2. 指针参数的前置条件

函数内部解引用前，必须明确指针不是 `NULL`，或者由接口约定调用者一定传入有效地址。写函数时要把这个前置条件说清楚。

## 3. 完整示例

```c
#include <stdio.h>

void print_pointed_value(const int *value)
{
    if (value == NULL) {
        printf("没有可读取的整数。\n");
        return;
    }

    printf("pointed value = %d\n", *value);
}

int main(void)
{
    int score = 95;

    print_pointed_value(&score);
    print_pointed_value(NULL);

    return 0;
}
```

## 挖空任务

1. 写出 `print_pointed_value` 的指针参数；
2. 在函数内部检查空指针；
3. 完成通过解引用读取值的语句；
4. 在 `main` 中传入 `score` 的地址；
5. 再传入 `NULL`，观察失败路径。

## 自测题

1. 为什么函数参数要写成指针类型？
2. 调用时为什么传 `&score` 而不是 `score`？
3. 指针参数是否复制了整个整数对象？
4. 为什么函数需要处理 `NULL`？
5. 普通参数和指针参数在访问调用者数据时有什么区别？

## 验收标准

- [ ] 能定义指针参数；
- [ ] 能传入对象地址；
- [ ] 能在函数中安全解引用；
- [ ] 能解释指针参数和普通参数的差异。

