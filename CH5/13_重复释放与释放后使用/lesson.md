# 第 13 课：重复释放与释放后使用

## 学习目标

区分 double free 和 use-after-free，并学会用所有权规则、别名管理和置空措施避免它们。

## 核心概念

- 同一动态对象只能被释放一次。
- 释放后继续读写是 use-after-free。
- 释放后立即把指针设为 `NULL`，可以降低同一个变量再次误用的风险。
- 另一个别名不会因为原指针置空而自动失效。
- 本课危险分支只用于 Sanitizer 观察，默认路径保持安全。

## 完整示例

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof *value);

    if (value == NULL) {
        return 1;
    }

    *value = 10;
    printf("before release = %d\n", *value);

#if defined(DOUBLE_FREE) || defined(USE_AFTER_FREE)
    int *alias = value;
#endif

    free(value);
    value = NULL;

#if defined(DOUBLE_FREE)
    free(alias);              /* 诊断用：alias 仍指向已释放对象 */
#elif defined(USE_AFTER_FREE)
    printf("%d\n", *alias);   /* 诊断用：释放后使用 */
#else
    puts("safe path");
#endif

    return 0;
}
```

默认编译：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

诊断构建：

```sh
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 \
    -fsanitize=address,undefined \
    -DDOUBLE_FREE practice.c -o double_free_san
./double_free_san
```

把 `-DDOUBLE_FREE` 换成 `-DUSE_AFTER_FREE` 可以观察另一类错误。诊断分支不是正常业务代码。

## 练习任务

1. 运行默认安全路径，确认释放后原变量已经置空。
2. 在 `practice.c` 中补齐别名和诊断分支。
3. 分别用 ASan 观察 double free 和 use-after-free。
4. 解释为什么把一个变量设为 `NULL` 不能让其他别名自动安全。
5. 写出一条项目中的所有权约定，说明谁负责释放节点或缓冲区。

## 本课检查点

- [ ] 我能区分重复释放和释放后使用。
- [ ] 我知道 `free(NULL)` 安全，但别名可能仍然悬空。
- [ ] 我实际看过至少一种 Sanitizer 报告。
- [ ] 我能用统一销毁函数减少释放责任分散。

