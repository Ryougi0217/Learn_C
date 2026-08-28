# 第 16 课：指针验收

本课没有额外脚本。请直接使用前面课程的脚本和你自己的代码完成验收。

## 一、概念验收

不看笔记，用自己的话回答：

1. 什么是地址？它和变量的值有什么区别？
2. `&value`、`pointer`、`*pointer` 分别表示什么？
3. 为什么 `int *p = NULL;` 后不能直接执行 `*p`？
4. 指针作为函数参数时，函数为什么能够修改调用者的变量？
5. `array` 和 `&array[0]` 为什么常常可以用于同一个遍历起点？
6. 指针加一实际移动多少距离？为什么不能简单理解成地址加一字节？
7. 为什么字符串指针遍历必须在 `\0` 处停止？
8. `int **pp` 与 `int *p` 的类型区别是什么？
9. `const int *p` 和 `int *const p` 的限制分别作用于谁？
10. 为什么在函数参数中，`sizeof(values)` 可能不是调用者数组的总大小？
11. 什么情况下会产生悬空指针？
12. 为什么“指针不是 NULL”不能证明它一定安全？

## 二、画图验收

在纸上画出每一行执行后的关系：

```c
int first = 10;
int second = 20;
int *p = &first;
int **pp = &p;

*p = 11;
p = &second;
**pp = 21;
```

最后写出：

- `first` 的值；
- `second` 的值；
- `p` 指向哪个变量；
- `*pp` 的值；
- `**pp` 的值。

## 三、代码验收

### 任务 A：交换两个整数

不使用全局变量，手写：

```c
static void swap_ints(int *left, int *right)
{
    /* 由你完成 */
}
```

要求：

- 能交换两个调用者变量；
- 参数为空时不会直接解引用；
- 在 `main` 中打印交换前后的结果。

### 任务 B：查找第一个数字

手写一个函数，返回字符串中第一个 ASCII 数字的指针；如果没有数字，返回 `NULL`。

```c
static const char *find_first_digit(const char *text)
{
    /* 由你完成 */
}
```

要求使用指针游标，不使用数组下标。

### 任务 C：指针版文本统计

完成第 15 课的 `practice.c`，并测试：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
printf 'C pointers 3\n' | ./practice
```

至少确认：

- 字母数量正确；
- 数字数量正确；
- 连续空白不会多算单词；
- 空输入不会越界。

## 四、风险验收

运行第 13 课的安全路径：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic \
    ../13_悬空指针与局部变量地址/practice.c -o dangling_safe
./dangling_safe
```

然后只在诊断环境中编译危险分支：

```sh
gcc -std=c17 -Wall -Wextra -pedantic \
    -DTRY_DANGLING -g -O0 \
    -fsanitize=address,undefined \
    ../13_悬空指针与局部变量地址/practice.c -o dangling_san
./dangling_san
```

记录：

1. 编译器是否提示返回局部变量地址；
2. Sanitizer 是否报告生命周期或无效访问问题；
3. 为什么默认安全路径没有这个问题。

## 五、推荐编译命令

在每个练习目录内运行：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

如果某个练习故意保留未定义行为，使用单独的诊断构建，不要把诊断二进制当作正常程序。

## 通过标准

满足以下条件，才算真正完成 CH4：

- [ ] 能独立解释一级指针和二级指针；
- [ ] 能画出至少三种指针关系图；
- [ ] 手写过取地址、解引用、指针参数和指针运算；
- [ ] 手写完成第 15 课的三个统计函数；
- [ ] 写过一个通过指针修改调用者变量的函数；
- [ ] 解释过 `const` 与指针的两种常见组合；
- [ ] 解释过 `sizeof(array)` 与 `sizeof(pointer)` 的区别；
- [ ] 能指出至少三种悬空指针来源；
- [ ] 实际编译并运行过自己的代码；
- [ ] 看过编译器警告或 Sanitizer 的诊断结果。

如果这些项目中还有一项只能“看懂答案”而不能“重新敲出来”，就先回到对应课程重写。

