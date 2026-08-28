# CH10：调试、测试与综合项目

本章学习如何用编译器警告、调试器、Sanitizer、断言和测试矩阵定位问题，并完成三个综合项目。

## 课程目录

01. [第 1 课：使用编译器警告定位问题](./01_使用编译器警告定位问题/lesson.md)
02. [第 2 课：调试器断点](./02_调试器断点/lesson.md)
03. [第 3 课：单步执行与查看变量](./03_单步执行与查看变量/lesson.md)
04. [第 4 课：查看调用栈](./04_查看调用栈/lesson.md)
05. [第 5 课：AddressSanitizer](./05_AddressSanitizer/lesson.md)
06. [第 6 课：UndefinedBehaviorSanitizer](./06_UndefinedBehaviorSanitizer/lesson.md)
07. [第 7 课：断言与测试程序](./07_断言与测试程序/lesson.md)
08. [第 8 课：最小输入与最小复现](./08_最小输入与最小复现/lesson.md)
09. [第 9 课：正常、边界与错误输入设计](./09_正常边界错误输入设计/lesson.md)
10. [第 10 课：综合项目 A——二进制文件分析器](./10_综合项目二进制文件分析器/lesson.md)
11. [第 11 课：综合项目 B——命令行通讯录](./11_综合项目命令行通讯录/lesson.md)
12. [第 12 课：综合项目 C——文本日志分析器](./12_综合项目文本日志分析器/lesson.md)
13. [第 13 课：多文件构建与 README](./13_多文件构建与README/lesson.md)

## 常用命令

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
gcc -std=c17 -Wall -Wextra -g -O0 -fsanitize=address,undefined practice.c -o practice_san
./practice
```

诊断分支需要显式定义对应宏；不要把故意触发错误的构建当作正常版本。

