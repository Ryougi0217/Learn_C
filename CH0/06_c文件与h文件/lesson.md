# 第 6 课：`.c` 文件与 `.h` 文件

## 本课目标

完成本课后，你应该能够：

- 解释头文件中为什么放声明，而源文件中通常放实现；
- 使用头文件保护宏，避免同一声明被重复处理；
- 用多个 `.c` 文件分别编译，再链接成一个程序；
- 区分 `#include "自己的头文件"` 与链接阶段提供的实现。

## 1. 声明和实现分离

本课的练习故意拆成三个文件：

```text
practice_main.c       使用功能的地方
practice_greeting.h   对外声明
practice_greeting.c   功能实现
```

头文件适合表达“其他文件可以调用什么”：

```c
void print_greeting(const char *name);
```

源文件适合表达“这个功能具体怎么做”：

```c
void print_greeting(const char *name)
{
    /* 具体实现 */
}
```

`practice_main.c` 通过 `#include "practice_greeting.h"` 看到声明；链接时，链接器再从 `practice_greeting.o` 中找到实现。仅仅包含头文件，不会自动把实现复制进程序。

## 2. 头文件保护宏

头文件通常写成：

```c
#ifndef PRACTICE_GREETING_H
#define PRACTICE_GREETING_H

/* 声明 */

#endif
```

第一次处理时宏尚未定义，声明会被保留；再次处理时宏已经定义，内容会被跳过。保护宏名称要前后一致，并尽量与文件名有清晰对应关系。

## 3. 分别编译和链接

GCC/Clang 风格命令：

```text
gcc -std=c17 -Wall -Wextra -pedantic -c practice_greeting.c -o practice_greeting.o
gcc -std=c17 -Wall -Wextra -pedantic -c practice_main.c -o practice_main.o
gcc practice_main.o practice_greeting.o -o practice
./practice
```

也可以由编译器驱动程序一次完成：

```text
gcc -std=c17 -Wall -Wextra -pedantic practice_main.c practice_greeting.c -o practice
```

不过本课建议先使用分步命令，因为这样能看清“分别编译”和“最后链接”。MSVC 中可尝试：

```text
cl /std:c17 /W4 /c practice_main.c practice_greeting.c
link practice_main.obj practice_greeting.obj /out:practice.exe
practice.exe
```

## 4. 常见错误定位

| 现象 | 可能原因 |
| --- | --- |
| `practice_greeting.h: No such file` | 头文件不在当前目录，或文件名写错 |
| 编译 `practice_main.c` 时找不到 `print_greeting` 声明 | 没有包含头文件，或声明名称不一致 |
| 链接时 `undefined reference` / `unresolved external` | 忘记把实现所在的目标文件加入链接命令 |
| 重复定义 | 把同一个非 `static` 实现放进了多个源文件，或头文件缺少保护 |

## 填空任务

1. 在三个文件中完成标记的填空。
2. 先只编译 `practice_main.c`，观察它为什么不能独立完成链接。
3. 再只编译 `practice_greeting.c`，确认它能生成自己的目标文件。
4. 把两个目标文件一起链接。
5. 临时从链接命令中删除 `practice_greeting.o`，记录错误类型，再恢复命令。

## 自测题

1. 为什么函数声明适合放在 `.h` 文件中？
2. `#include` 是复制实现，还是让当前文件看到声明文本？
3. 头文件保护宏解决了什么问题？
4. 编译成功但链接失败，说明哪个阶段已经完成、哪个阶段还没有完成？
5. 为什么实现文件通常不直接被另一个 `.c` 文件 `#include`？

## 验收标准

- [ ] 能说明三个练习文件各自的职责；
- [ ] 能分别生成两个目标文件；
- [ ] 能把两个目标文件链接成可执行文件；
- [ ] 能解释缺少实现目标文件时的链接错误；
- [ ] 能说出头文件保护宏的作用。
