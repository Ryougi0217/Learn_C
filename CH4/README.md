# CH4：指针

本章建立“对象、地址、指针和值”之间的关系，并练习用指针读取和修改数据。后半章会把指针和数组、字符串、二级指针、`const`、函数参数结合起来，最后完成指针版文本分析工具。

## 练习模式

本章采用“内存关系图 + 完整示例 + 关键挖空”的混合模式：

- 指针基础课会先画出对象和值的关系，再给出完整代码；
- 第一次遇到取地址、解引用、指针参数和二级指针时，会把关键表达式留为 `TODO`；
- 数组名、字符串和 `sizeof` 课程会给出可运行示例，重点是比较不同表达式的类型和含义；
- 悬空指针课程会使用受控的错误分支，避免把未定义行为误当成稳定结果；
- 手绘指针关系图课不额外设置脚本，练习重点是根据代码画出箭头；
- 指针版文本分析项目会保留函数参数和核心遍历逻辑，让你亲手把数组下标改写为指针访问；
- 涉及未定义行为时，优先使用 Sanitizer，并记录报告范围。

| 课次 | 主题 | 练习文件 |
| --- | --- | --- |
| 01 | 地址与内存 | `practice.c` |
| 02 | 指针变量 | `practice.c` |
| 03 | 取地址与解引用 | `practice.c` |
| 04 | 空指针 `NULL` | `practice.c` |
| 05 | 指针作为函数参数 | `practice.c` |
| 06 | 通过指针修改调用者变量 | `practice.c` |
| 07 | 数组名与首元素地址 | `practice.c` |
| 08 | 指针运算 | `practice.c` |
| 09 | 指针与字符串 | `practice.c` |
| 10 | 二级指针 | `practice.c` |
| 11 | `const` 与指针 | `practice.c` |
| 12 | `sizeof(array)` 与 `sizeof(pointer)` | `practice.c` |
| 13 | 悬空指针与局部变量地址 | `practice.c` |
| 14 | 绘制指针关系图 | 无额外脚本，按课件手绘 |
| 15 | 章节项目：指针版文本分析工具 | `practice.c` |
| 16 | 指针验收 | 无额外脚本，使用前 15 课材料 |

默认命令使用 GCC/Clang 风格：

```
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

需要检查越界、悬空指针等问题时使用：

```
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 -fsanitize=address,undefined practice.c -o practice_san
./practice_san
```

打印地址时，`%p` 对应的实参应转换为 `void *`；地址每次运行可能不同，不要把地址数值当成固定答案。

