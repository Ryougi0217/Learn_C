# 第 4 课：从终端编译和运行程序

## 本课目标

完成本课后，你应该能够：

- 用 `cd`/`pwd` 或 PowerShell 等价命令确认当前目录；
- 只用终端完成“编译 → 运行 → 传入参数”三个动作；
- 读懂终端命令中输入文件、输出文件和参数的位置；
- 区分“编译失败”“程序返回非 0”“程序输出错误”这三种现象。

## 1. 先确认当前目录

命令是在“当前工作目录”中执行的。Bash/WSL 中可使用：

```text
pwd
ls
```

PowerShell 中可使用：

```text
Get-Location
Get-ChildItem
```

如果列表中看不到 `practice.c`，先修正目录，不要直接修改源代码。Windows 路径和 WSL 路径的写法不同，请分别使用 `Get-Location` 或 `pwd` 确认当前目录。

## 2. 编译和运行

GCC/Clang 风格：

```text
gcc -std=c17 -Wall -Wextra -pedantic practice.c -o terminal_demo
./terminal_demo
```

Windows PowerShell：

```text
gcc -std=c17 -Wall -Wextra -pedantic practice.c -o terminal_demo.exe
.\terminal_demo.exe
```

MSVC 开发者命令提示符：

```text
cl /std:c17 /W4 practice.c /Fe:terminal_demo.exe
terminal_demo.exe
```

本课脚本读取命令行参数。参数不是编译器参数，而是运行程序时放在可执行文件后面的文字。例如：

```text
./terminal_demo compile
```

此时程序可以从 `argv` 中读取 `compile`。如果不提供参数，程序会使用默认值。

## 3. 三种结果要分开记录

| 现象 | 发生阶段 | 你要检查什么 |
| --- | --- | --- |
| 编译器打印 error，未生成可执行文件 | 编译/链接 | 源代码和编译命令 |
| 程序启动但返回非 0 | 运行 | 程序逻辑和输入 |
| 程序返回 0 但结果不符合预期 | 运行 | 输出逻辑和边界情况 |

终端中看到的“没有输出”也不等于没有运行成功，可能是程序没有打印内容。因此要结合返回状态、输出和生成文件一起判断。

## 填空任务

1. 在 `practice.c` 中修改默认目标名称。
2. 编译为名为 `terminal_demo` 的可执行文件。
3. 分别运行不带参数、带 `compile` 参数、带自定义参数的版本。
4. 在终端记录每次命令和输出。
5. 故意把源文件名写错一次，观察这是编译错误还是运行错误；随后恢复正确命令。

## 自测题

1. 为什么运行命令前要确认当前目录？
2. `./terminal_demo compile` 中哪一部分属于程序参数？
3. 编译器找不到源文件时，程序有没有机会启动？
4. `argc` 和 `argv` 分别表达什么？
5. 如果程序输出错误但编译没有报错，应优先检查哪个阶段？

## 验收标准

- [ ] 能用终端确认脚本所在目录；
- [ ] 能用终端生成可执行文件并运行；
- [ ] 能得到至少两种不同的命令行输出；
- [ ] 能解释编译参数和程序参数的区别；
- [ ] 能把一次失败命令恢复成可运行命令。
