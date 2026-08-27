# CH1：基础语法与输入输出

本章从“程序如何开始和结束”出发，逐步学习 C 的基本数据类型、变量、运算符和终端输入输出，最后完成一个成绩统计程序。

## 练习模式

本章采用“完整示例 + 关键挖空”的混合模式：

- `lesson.md` 会先解释概念，并给出完整代码示例和预期结果；
- 基础类型、变量、运算符和已经学过的 `printf` 通常给出可运行骨架，重点是观察、修改和预测；
- 第一次学习 `scanf` 时，会把格式字符串、地址参数等关键位置留空；
- 显式类型转换和章节项目会保留少量核心表达式，让你必须亲手写出类型和逻辑；
- 诊断课会使用独立的错误宏，方便你一次只观察一种错误；
- 完成后至少做一次正常输入和一次边界测试，不要只追求“能编译”。

`TODO` 不是答案提示的替代品。先读同目录 `lesson.md` 的完整示例，再自己写入练习脚本。

| 课次 | 主题 | 练习文件 |
| --- | --- | --- |
| 01 | `main` 函数与返回值 | `practice.c` |
| 02 | 注释、语句与代码块 | `practice.c` |
| 03 | 整数类型 | `practice.c` |
| 04 | 浮点类型 | `practice.c` |
| 05 | `signed` 与 `unsigned` | `practice.c` |
| 06 | 变量声明、初始化与常量 | `practice.c` |
| 07 | 算术、比较、逻辑与赋值运算符 | `practice.c` |
| 08 | `printf` 与格式说明符 | `practice.c` |
| 09 | `scanf` 与返回值检查 | `practice.c` |
| 10 | 显式类型转换 | `practice.c` |
| 11 | `sizeof` | `practice.c` |
| 12 | 基础语法常见错误 | `practice.c` |
| 13 | 章节项目：成绩统计程序 | `practice.c` |
| 14 | 基础语法与输入输出验收 | 无额外脚本，使用前 13 课材料 |

除特别说明外，示例命令使用 GCC/Clang 风格：

```
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

Windows PowerShell 中运行当前目录下的程序通常写作 `.\practice.exe`；如果使用 MSVC，请参照 CH0 的编译命令，把 GCC 选项换成 MSVC 对应选项。
```


