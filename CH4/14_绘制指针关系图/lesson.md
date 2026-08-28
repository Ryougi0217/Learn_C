# 第 14 课：绘制指针关系图

## 学习目标

本课不新增脚本，重点是把指针关系画出来。完成后，你应该能够：

1. 区分变量本身、变量的值和变量的地址。
2. 画出一级指针指向普通变量的关系。
3. 画出二级指针经过两次解引用后的关系。
4. 根据图判断每个表达式访问的是哪一个对象。

## 1. 一级指针关系图

先看这段代码：

```c
int score = 95;
int *pointer = &score;
```

可以画成：

```text
pointer ───────► score
                 value: 95
```

解释：

- `score` 是一个真正保存整数的变量；
- `score` 的值是 `95`；
- `&score` 是 `score` 的地址；
- `pointer` 保存了这个地址；
- `*pointer` 访问 `pointer` 指向的 `score`。

注意，箭头表示“保存的地址指向哪里”，不是表示变量的数值相等。

## 2. 二级指针关系图

继续增加一层：

```c
int score = 95;
int *pointer = &score;
int **double_pointer = &pointer;
```

关系图可以画成：

```text
double_pointer ─────► pointer ─────► score
                                      value: 95
```

三个表达式分别对应：

| 表达式 | 访问结果 |
| --- | --- |
| `double_pointer` | `pointer` 的地址 |
| `*double_pointer` | `pointer` 中保存的地址 |
| `**double_pointer` | `score` 的值 |

因此：

- `double_pointer == &pointer`；
- `*double_pointer == pointer`；
- `**double_pointer == score`。

## 3. 完整示例：用代码验证图

```c
#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int score = 95;
    int *pointer = &score;
    int **double_pointer = &pointer;

    printf("score = %d\n", score);
    printf("*pointer = %d\n", *pointer);
    printf("**double_pointer = %d\n", **double_pointer);

    *double_pointer = NULL;

    printf("pointer is now %s\n",
           pointer == NULL ? "NULL" : "valid");

    return 0;
}
```

执行 `*double_pointer = NULL;` 后，修改的是 `pointer` 本身：

```text
double_pointer ─────► pointer ─────► NULL
```

它没有修改 `score` 的值，只是让一级指针不再指向 `score`。

## 4. 画图时的步骤

遇到指针题，可以按下面的顺序画：

1. 先画出每个普通变量的方框；
2. 在方框中写出当前值；
3. 给每个指针变量单独画一个方框；
4. 把指针变量中保存的地址画成箭头；
5. 每执行一次解引用，就沿着箭头走一格；
6. 每执行一次赋值，就只修改表达式左侧对应对象。

例如：

```c
int number = 7;
int *first = &number;
int **second = &first;

**second = 12;
```

最后一行沿着两条箭头找到 `number`，所以最终：

```text
second ─────► first ─────► number
                                  value: 12
```

## 5. 手绘练习

请在纸上或 Markdown 中分别画出每一步的图。

### 练习 A

```c
int a = 10;
int b = 20;
int *p = &a;

p = &b;
```

要求说明：

- 执行 `p = &b;` 前后，箭头发生了什么变化；
- `a` 和 `b` 的值是否被自动交换。

### 练习 B

```c
int value = 3;
int *p = &value;
int **q = &p;

**q = 8;
```

要求说明：

- `q` 指向哪个变量；
- `*q` 是什么；
- `**q` 修改了谁。

### 练习 C

```c
int value = 3;
int *p = &value;
int **q = &p;

*q = NULL;
```

要求说明：

- 哪个指针变成了空指针；
- `value` 是否仍然存在；
- 此时还能不能安全地执行 `**q`。

## 6. 自我检查

不看上面的表格，解释下面表达式的含义：

1. `&score`；
2. `pointer`；
3. `*pointer`；
4. `&pointer`；
5. `double_pointer`；
6. `**double_pointer`。

## 本课检查点

- [ ] 我能画出一级指针的箭头。
- [ ] 我能画出二级指针的两层箭头。
- [ ] 我知道解引用一次和两次分别访问什么。
- [ ] 我能根据赋值语句更新指针关系图。
- [ ] 我能解释 `*double_pointer = NULL;` 修改的是谁。

