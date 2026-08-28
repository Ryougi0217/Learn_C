# 第 10 课：二级指针

## 本课目标

完成本课后，你应该能够：

- 说明二级指针保存的是什么地址；
- 区分 `pointer`、`*pointer` 和 `**pointer`；
- 通过二级指针修改一级指针；
- 在多层解引用前检查每一层是否有效。

## 1. 两层关系

```c
int score = 95;
int *pointer = &score;
int **double_pointer = &pointer;
```

关系可以写成：

```
double_pointer
    ↓
pointer
    ↓
score
值：95
```

因此：

- `double_pointer` 保存 `pointer` 的地址；
- `*double_pointer` 得到 `pointer`；
- `**double_pointer` 得到 `score` 的值。

## 2. 修改一级指针

二级指针可以改变一级指针当前指向的对象：

```c
int first_value = 10;
int second_value = 20;
int *pointer = &first_value;
int **double_pointer = &pointer;

*double_pointer = &second_value;
printf("%d\n", *pointer);
```

赋值后，`pointer` 从指向 `first_value` 改为指向 `second_value`。

## 3. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int score = 95;
    int replacement = 100;
    int *pointer = &score;
    int **double_pointer = &pointer;

    printf("before = %d\n", **double_pointer);

    *double_pointer = &replacement;

    printf("after = %d\n", **double_pointer);
    printf("pointer now points to = %d\n", *pointer);

    return 0;
}
```

## 安全检查

如果允许指针为空，至少要按从外到内的顺序检查：

```c
if (double_pointer != NULL && *double_pointer != NULL) {
    printf("%d\n", **double_pointer);
}
```

空的一级指针和空的二级指针是两个不同的失败状态。

## 挖空任务

1. 完成一级指针的初始化；
2. 完成二级指针保存一级指针地址的表达式；
3. 通过二级指针让一级指针改指向另一个整数；
4. 写出两层非空检查；
5. 画出三者之间的箭头关系。

## 自测题

1. `double_pointer` 保存的是什么地址？
2. `*double_pointer` 和 `**double_pointer` 分别是什么？
3. 为什么 `*double_pointer = &replacement` 会改变一级指针？
4. 多层解引用时为什么要从外到内检查？
5. 二级指针和“指向一个整数的指针”有什么区别？

## 验收标准

- [ ] 能声明二级指针；
- [ ] 能解释两层解引用；
- [ ] 能通过二级指针修改一级指针；
- [ ] 能写出基本的空指针保护。

