# 第 7 课：调试构建与 Sanitizer 入门

## 本课目标

完成本课后，你应该能够：

- 区分调试构建和发布构建的目的；
- 使用调试信息选项生成便于定位问题的程序；
- 用 AddressSanitizer 发现数组/堆内存越界；
- 先根据报告定位问题，再修改代码并重新验证。

## 1. 调试构建和发布构建

调试构建通常重视“容易观察”：

- 保留调试信息；
- 使用较低优化等级，尽量保持源码和执行顺序容易对应；
- 打开较多警告和运行时检查。

GCC/Clang 的一个常见调试命令是：

```
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 practice.c -o practice_debug
```

发布构建通常重视性能和体积，例如：

```
gcc -std=c17 -Wall -Wextra -pedantic -O2 practice.c -o practice_release
```

`-g` 主要加入调试信息；`-O0` 和 `-O2` 是优化级别。优化不是“让代码更正确”，而是改变编译器优化程序的方式。

## 2. AddressSanitizer

AddressSanitizer（ASan）是一类运行时检测工具，可以帮助发现：

- 堆缓冲区越界；
- 栈缓冲区越界；
- 释放后使用；
- 重复释放等部分内存错误。

GCC/Clang 示例：

```
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 \
    -fsanitize=address,undefined -fno-omit-frame-pointer \
    practice.c -o practice_san
./practice_san
```

如果你的终端不接受反斜杠换行，可以把命令写成一行。MSVC 的较新版本在受支持的配置下可以尝试：

```
cl /std:c17 /W4 /Zi /fsanitize=address practice.c
practice.exe
```

如果 MSVC 不认识 `/fsanitize:address`，改用 GCC/Clang 环境完成本课即可；不要把“工具选项不存在”误判成代码没有问题。

## 3. 读 Sanitizer 报告

`practice.c` 已经给出了申请后的空指针检查和输出循环。需要你手写的是两个新内存 API 的关键位置：

- `malloc` 的申请表达式；
- `free` 的实参。

写完 `malloc` 后，脚本中的第一条循环故意使用 `i <= count`。先用 Sanitizer 构建运行，观察报告中的错误类别、源码行号和访问位置；然后把它改成合法边界 `i < count`，最后补上 `free(numbers)`。

运行时重点找：

1. 错误类别，例如 `heap-buffer-overflow`；
2. 报告指出的源码文件和行号；
3. 哪一次访问超出了申请的元素数量；
4. 分配位置和出错位置之间的关系。

修复后重新编译、重新运行。一次“没有看到报告”只说明这次输入和这类检查没有发现问题，不等于所有内存错误都不存在。

## 填空/修改任务

1. 填写 `malloc` 的申请表达式；
2. 编译 Sanitizer 版本并观察故意的越界；
3. 修复 `i <= count`，使每个合法下标只访问一次；
4. 填写 `free(numbers)` 并重新构建；
5. 分别生成 debug 和 release 版本，比较编译命令中 `-g/-O0` 与 `-O2` 的差异。

## 自测题

1. 为什么调试构建常使用 `-g -O0`？
2. `malloc(count * sizeof *numbers)` 申请的是多少个字节？
3. `count` 个元素的合法下标范围是什么？
4. Sanitizer 报告中的源码行号为什么很有价值？
5. Sanitizer 没有报告错误，是否能证明程序没有任何 bug？为什么？

## 验收标准

- [ ] 能分别生成 debug、release 和 sanitizer 版本；
- [ ] 能复述报告指出的越界位置；
- [ ] 能修复循环边界并让 sanitizer 版本重新运行；
- [ ] 能解释 `-g`、`-O0`、`-O2` 的基本目的；
- [ ] 能明确说明一次检查的结论范围，不夸大为“程序绝对安全”。
```


