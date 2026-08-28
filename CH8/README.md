# CH8：多文件项目与预处理

本章把声明、实现、预处理、编译和链接放到真实的多文件项目中练习。

## 课程目录

01. [第 1 课：声明与实现分离](./01_声明与实现分离/lesson.md)
02. [第 2 课：头文件保护宏](./02_头文件保护宏/lesson.md)
03. [第 3 课：include 查找逻辑](./03_include查找逻辑/lesson.md)
04. [第 4 课：宏常量](./04_宏常量/lesson.md)
05. [第 5 课：函数式宏的风险](./05_函数式宏的风险/lesson.md)
06. [第 6 课：条件编译](./06_条件编译/lesson.md)
07. [第 7 课：文件作用域的 static](./07_文件作用域的static/lesson.md)
08. [第 8 课：函数内部的 static](./08_函数内部的static/lesson.md)
09. [第 9 课：extern](./09_extern/lesson.md)
10. [第 10 课：分别编译多个源文件](./10_分别编译多个源文件/lesson.md)
11. [第 11 课：链接多个目标文件](./11_链接多个目标文件/lesson.md)
12. [第 12 课：简单 Makefile 或构建脚本](./12_简单Makefile或构建脚本/lesson.md)
13. [第 13 课：项目目录设计](./13_项目目录设计/lesson.md)
14. [第 14 课：README 编写](./14_README编写/lesson.md)
15. [第 15 课：章节项目——模块化文件初检工具](./15_章节项目模块化文件初检工具/lesson.md)

## 常用构建

单文件课程：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

多文件课程要把对应的 `.c` 一起编译，或执行目录中的 Makefile。不要把 `.h` 单独传给链接器。

