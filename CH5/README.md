# CH5：动态内存

本章从栈与堆的区别开始，逐步练习 `malloc`、`calloc`、`realloc`、`free`、动态数组、字符串复制和内存所有权。

## 学习方式

- 每一课的 `lesson.md` 先阅读概念和完整示例。
- 再打开同目录的 `practice.c`，亲手补完 TODO。
- 默认脚本尽量保持安全；带有诊断宏的课程只在 Sanitizer 构建中观察错误。
- 遇到申请失败、扩容失败或输入异常，都要先走失败路径，不能继续解引用无效指针。

## 课程目录

01. [第 1 课：栈区与堆区](./01_栈区与堆区/lesson.md)
02. [第 2 课：malloc](./02_malloc/lesson.md)
03. [第 3 课：calloc](./03_calloc/lesson.md)
04. [第 4 课：realloc](./04_realloc/lesson.md)
05. [第 5 课：free](./05_free/lesson.md)
06. [第 6 课：检查内存申请结果](./06_检查内存申请结果/lesson.md)
07. [第 7 课：计算申请空间的字节数](./07_计算申请空间的字节数/lesson.md)
08. [第 8 课：动态数组](./08_动态数组/lesson.md)
09. [第 9 课：动态数组扩容](./09_动态数组扩容/lesson.md)
10. [第 10 课：动态复制字符串](./10_动态复制字符串/lesson.md)
11. [第 11 课：内存所有权](./11_内存所有权/lesson.md)
12. [第 12 课：内存泄漏](./12_内存泄漏/lesson.md)
13. [第 13 课：重复释放与释放后使用](./13_重复释放与释放后使用/lesson.md)
14. [第 14 课：realloc 失败处理](./14_realloc失败处理/lesson.md)
15. [第 15 课：章节项目——动态成绩管理程序](./15_章节项目动态成绩管理程序/lesson.md)
16. [第 16 课：动态内存与 Sanitizer 验收](./16_动态内存与Sanitizer验收/lesson.md)

## 常用编译命令

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

诊断课程可以使用：

```sh
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 \
    -fsanitize=address,undefined,leak practice.c -o practice_san
./practice_san
```

完成本章后，你应该能解释每块堆内存的申请位置、使用范围、所有权和释放位置。

