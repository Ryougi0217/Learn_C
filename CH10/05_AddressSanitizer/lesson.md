# 第 5 课：AddressSanitizer

## 学习目标

使用 AddressSanitizer 检测数组越界和释放后使用等地址错误。

## 核心概念

- ASan 在运行时给内存访问增加检查。
- 它能报告错误位置、访问类型和调用栈。
- 诊断分支要和正常分支分开编译。
- Sanitizer 报告是证据，修复仍需要回到生命周期和边界设计。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

int main(void)
{
    int values[3] = {10, 20, 30};

#if defined(ASAN_DEMO)
    printf("%d\n", values[3]);  /* 诊断用越界访问 */
#else
    printf("%d\n", values[2]);
#endif

    return 0;
}
```

## 练习任务

1. 先编译并运行默认安全路径。
2. 再使用：
```sh
gcc -std=c17 -Wall -Wextra -g -O0 -fsanitize=address practice.c -o asan_demo
```
3. 加上 `-DASAN_DEMO` 运行，记录报告中的源代码行。
4. 修复边界后重新运行，确认报告消失。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键函数或测试。
- [ ] 我记录过一个可复现的输入、输出或诊断结果。

