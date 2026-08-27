# CH3：数组与字符串

本章学习如何连续保存一组数据、访问数组元素，并理解字符数组与 C 字符串之间的关系。后半章会进一步练习字符串库函数、逐行输入、换行处理和手动实现字符串操作，最后完成一个文本分析工具。

## 练习模式

本章采用“完整示例 + 关键挖空”的混合模式：

- 一维数组、二维数组和 `sizeof` 等基础课通常给出可运行脚本，重点是修改数据、预测输出和检查下标；
- 第一次遇到字符串库函数、`memcpy`/`memcmp`/`memset` 或 `fgets` 时，会把函数调用的关键参数留为 `TODO`；
- 字符串结尾、数组容量和换行处理会保留边界逻辑，让你通过实验理解 `\0`、长度和容量的区别；
- 手动字符串函数和章节项目会留下函数体或核心算法，由你亲手实现；
- `lesson.md` 先提供完整示例、命令和预期现象，`practice.c` 用来练习，不是直接复制答案；
- 涉及越界的实验必须优先使用 Sanitizer，并记录“错误位置、原因和修复”。

| 课次 | 主题 | 练习文件 |
| --- | --- | --- |
| 01 | 一维数组 | `practice.c` |
| 02 | 二维数组 | `practice.c` |
| 03 | 数组下标与边界 | `practice.c` |
| 04 | 数组长度与元素大小 | `practice.c` |
| 05 | 字符数组与 C 字符串 | `practice.c` |
| 06 | 字符串结尾的 `\0` | `practice.c` |
| 07 | 字符串库函数 | `practice.c` |
| 08 | `memcpy`、`memcmp` 与 `memset` | `practice.c` |
| 09 | 使用 `fgets` 读取一行 | `practice.c` |
| 10 | 处理输入末尾换行符 | `practice.c` |
| 11 | 手动实现字符串长度、复制与反转 | `practice.c` |
| 12 | 数组容量与字符串长度 | `practice.c` |
| 13 | 章节项目：文本分析工具 | `practice.c` |
| 14 | 数组、字符串与越界验收 | 无额外脚本，使用前 13 课材料 |

默认命令使用 GCC/Clang 风格：

```
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

需要观察越界时使用：

```
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 -fsanitize=address,undefined practice.c -o practice_san
./practice_san
```

Windows PowerShell 中通常使用 `.\practice.exe` 或 `.\practice_san.exe` 运行当前目录下的程序。

