# 第 7 课：字符串库函数

## 本课目标

完成本课后，你应该能够：

- 使用 `strlen` 获取 C 字符串的可见字符数量；
- 使用 `strcmp` 比较两个字符串；
- 使用 `strcpy` 把字符串复制到容量足够的目标数组；
- 说明这些函数都依赖源字符串的 `\0`。

## 1. 先包含头文件

字符串函数的声明在 `<string.h>` 中：

```c
#include <string.h>
```

没有包含正确头文件时，编译器可能无法正确检查函数调用。

## 2. 三个常用函数

`strlen` 返回字符串长度，不包含结尾的 `\0`：

```c
size_t length = strlen("hello");  /* length 是 5 */
```

`strcmp` 按字典序比较两个字符串：

```c
int result = strcmp("cat", "car");
```

返回值等于 0 表示相等；小于 0 或大于 0 表示顺序关系，不应依赖它一定返回 -1 或 1。

`strcpy` 将源字符串及其结尾的 `\0` 复制到目标数组：

```c
char copied[16];
strcpy(copied, "hello");
```

目标数组必须足够大，否则会产生越界写入。实际项目中还要考虑更严格的长度检查。

## 3. 完整示例

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *left = "cat";
    const char *right = "car";
    char copied[16];

    size_t length = strlen(left);
    int comparison = strcmp(left, right);
    strcpy(copied, left);

    printf("left = %s\n", left);
    printf("length = %zu\n", length);
    printf("comparison = %d\n", comparison);
    printf("copied = %s\n", copied);

    return 0;
}
```

## 使用边界

这些函数把输入当作以 `\0` 结尾的字符串。它们不知道目标数组的容量，也不会替你检查所有业务约束。尤其是 `strcpy`，调用前必须先证明目标空间足够。

## 挖空任务

1. 在脚本中完成 `strlen` 的实参；
2. 完成 `strcmp` 的两个实参；
3. 完成 `strcpy` 的目标和源参数；
4. 把目标数组容量改小，先预测风险，再恢复安全容量；
5. 比较相等、左侧更小和左侧更大的字符串。

## 自测题

1. `strlen` 返回值是否包含 `\0`？
2. `strcmp` 返回 0 表示什么？
3. 为什么不能假设 `strcmp` 只返回 -1、0、1？
4. `strcpy` 需要检查什么容量条件？
5. 为什么字符串函数依赖结尾标记？

## 验收标准

- [ ] 能正确包含 `<string.h>`；
- [ ] 能使用 `strlen`、`strcmp` 和 `strcpy`；
- [ ] 能解释长度、比较结果和复制目标；
- [ ] 能指出目标空间不足的风险。

