# C 语言学习路径

本目录按章节和课程组织：

1. 进入对应课程文件夹，先阅读 `lesson.md`。
2. 先理解并运行 md 中的完整示例。
3. 再打开 `practice.c` 或该课的多文件练习，亲手补 TODO。
4. 用严格编译选项构建，记录输入、输出和错误信息。
5. 通过章节验收后，再进入下一章。

## 章节导航

- [CH0：环境与编译模型](./CH0/README.md)
- [CH1：基础语法与输入输出](./CH1/README.md)
- [CH2：分支、循环与函数](./CH2/README.md)
- [CH3：数组与字符串](./CH3/README.md)
- [CH4：指针](./CH4/README.md)
- [CH5：动态内存](./CH5/README.md)
- [CH6：结构体、枚举、联合体与类型设计](./CH6/README.md)
- [CH7：文件与二进制数据](./CH7/README.md)
- [CH8：多文件项目与预处理](./CH8/README.md)
- [CH9：基础数据结构与算法](./CH9/README.md)
- [CH10：调试、测试与综合项目](./CH10/README.md)
- [附录：C 语言风险检查](./附录_风险检查/README.md)
- [最终完成判断](./最终完成判断/lesson.md)

## 通用编译命令

单文件练习通常使用：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

多文件练习要按照课程中的头文件搜索路径和源文件列表编译。诊断课程使用 Sanitizer 时，只运行明确标注的安全或诊断分支。

## 学习原则

- 不要只复制完整示例；至少重新手敲每个新函数。
- 新函数或核心算法的 TODO 应自己完成，再对照参考实现。
- 遇到警告、越界、泄漏或未定义行为，先保留证据再修复。
- 章节项目完成后，一周后不看答案重写核心部分。
