# 第 3 课：取地址与解引用

## 本课目标

完成本课后，你应该能够：

- 使用 `&object` 获取对象地址；
- 使用 `*pointer` 读取指针指向的对象；
- 通过解引用修改一个可写对象；
- 按“先确认指向谁，再解引用”的顺序写代码。

## 1. 两个相反方向的操作

取地址把对象变成地址：

```c
int count = 3;
int *pointer = &count;
```

解引用把地址带回对象：

```c
printf("%d\n", *pointer);
```

对可写对象解引用还可以修改目标：

```c
*pointer = 10;
```

修改的是 `count`，不是指针变量 `pointer` 本身。

## 2. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int count = 3;
    int *pointer = &count;

    printf("before = %d\n", count);

    *pointer += 2;

    printf("after = %d\n", count);
    printf("through pointer = %d\n", *pointer);

    return 0;
}
```

`pointer` 在整个示例中都指向 `count`，所以通过 `*pointer` 写入会改变 `count`。

## 安全顺序

解引用前至少要确认：

1. 指针已经初始化；
2. 指针指向的对象仍然存在；
3. 指针类型与对象访问方式匹配；
4. 写入操作得到的内存确实可写。

## 挖空任务

1. 完成指针保存 `count` 地址的表达式；
2. 完成通过指针写入新值的表达式；
3. 运行前预测 `count` 的变化；
4. 增加一次读取和一次写入；
5. 说明 `pointer = ...` 与 `*pointer = ...` 修改的对象不同。

## 自测题

1. `&count` 的结果是什么？
2. `*pointer` 读取的是什么？
3. `*pointer = 10` 会改变指针地址吗？
4. 解引用前为什么要确认对象仍然存在？
5. 为什么不能对任意整数直接解引用？

## 验收标准

- [ ] 能正确取地址；
- [ ] 能正确解引用读取；
- [ ] 能通过解引用修改整数；
- [ ] 能说明指针赋值和目标赋值的区别。

