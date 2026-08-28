# 第 7 课：数组名与首元素地址

## 本课目标

完成本课后，你应该能够：

- 说明数组名在多数表达式中如何转换为首元素地址；
- 区分 `array`、`&array[0]` 和 `&array` 的含义；
- 使用指针读取数组元素；
- 知道 `sizeof` 和取地址是数组名不发生普通转换的典型场景。

## 1. 数组名和首元素

对于：

```c
int values[4] = {10, 20, 30, 40};
```

在大多数需要一个地址的表达式中，`values` 会表示首元素的地址，效果类似于 `&values[0]`。因此：

```c
int *first = values;
printf("%d\n", first[2]);
```

`first[2]` 和 `values[2]` 都表示第三个整数。

## 2. `&array` 不一样

`&values[0]` 的类型是指向 `int` 的指针；`&values` 的类型是指向整个数组的指针。它们打印出的起始地址通常相同，但指针加法的步长和类型不同。

本课先记住：访问首元素通常使用 `values` 或 `&values[0]`；`&values` 表示整个数组对象的地址。

## 3. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    int *first = values;

    printf("values address = %p\n", (void *) values);
    printf("first address = %p\n", (void *) first);
    printf("first[2] = %d\n", first[2]);
    printf("*(first + 3) = %d\n", *(first + 3));

    return 0;
}
```

数组名不是一个可以重新赋值的普通指针变量：

```c
/* values = first; */  /* 不允许给数组名赋值 */
```

但你可以让另一个指针变量指向数组的首元素。

## 挖空任务

1. 完成 `first` 的初始化；
2. 使用 `first` 读取第二个和最后一个元素；
3. 比较 `values` 和 `&values[0]` 的地址；
4. 观察 `sizeof values` 不等于 `sizeof first` 的原因；
5. 说明为什么数组名不能像普通指针一样重新指向别处。

## 自测题

1. `values` 在大多数表达式中会转换成什么？
2. `values[2]` 和 `*(values + 2)` 为什么等价？
3. `&values[0]` 和 `&values` 的类型是否相同？
4. 为什么数组名不能赋值？
5. 哪些常见场景中数组名不会转换成首元素指针？

## 验收标准

- [ ] 能让指针指向数组首元素；
- [ ] 能使用指针读取数组元素；
- [ ] 能解释数组名和首元素地址的关系；
- [ ] 能区分 `&array[0]` 和 `&array`。

