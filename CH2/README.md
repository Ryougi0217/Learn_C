# CH2：分支、循环与函数

本章学习如何让程序根据条件选择路径、重复执行任务，并把逻辑封装成可复用的函数。最后通过命令行菜单项目把三类结构组合起来。

## 练习模式

本章采用“完整控制流示例 + 函数关键位置挖空”的混合模式：

- `lesson.md` 会先给出完整示例，帮助你理解控制流或函数的基本形状；
- `if`、`switch`、循环、`break` 和 `continue` 等基础控制流课通常可以直接编译运行，练习重点是修改输入、预测边界和观察流程；
- 第一次系统学习函数时，会把函数体、返回表达式或调用实参留给你手写；
- 递归、函数拆分和基础算法会保留核心逻辑，要求你自己设计终止条件、循环和职责；
- 菜单项目给出整体框架，但仍留下累加逻辑和菜单循环条件；
- 只有编译、运行并完成边界测试，才算完成一课。

不要把 `lesson.md` 的完整示例当成练习答案直接粘贴。先读懂输入、处理、输出，再亲手写出 TODO 位置。

| 课次 | 主题 | 练习文件 |
| --- | --- | --- |
| 01 | `if`、`else if` 与 `else` | `practice.c` |
| 02 | `switch` 与 `case` | `practice.c` |
| 03 | `for` 循环 | `practice.c` |
| 04 | `while` 循环 | `practice.c` |
| 05 | `do while` 循环 | `practice.c` |
| 06 | `break` 与 `continue` | `practice.c` |
| 07 | 函数声明、定义与调用 | `practice.c` |
| 08 | 函数参数与返回值 | `practice.c` |
| 09 | 局部变量、全局变量与作用域 | `practice.c` |
| 10 | 递归基础 | `practice.c` |
| 11 | 函数拆分与职责划分 | `practice.c` |
| 12 | 基础算法练习 | `practice.c` |
| 13 | 章节项目：命令行菜单程序 | `practice.c` |
| 14 | 分支、循环与函数验收 | 无额外脚本，使用前 13 课材料 |

默认命令使用 GCC/Clang 风格：

```
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

Windows PowerShell 中通常使用 `.\practice.exe` 运行当前目录下的程序。若使用 MSVC，参考 CH0 中的对应参数写法。
```


