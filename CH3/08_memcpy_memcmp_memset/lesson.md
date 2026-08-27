# 第 8 课：`memcpy`、`memcmp` 与 `memset`

## 本课目标

完成本课后，你应该能够：

- 说明内存函数按字节处理一段内存；
- 使用 `memset` 把每个字节设置为同一个字节值；
- 使用 `memcpy` 复制不重叠的内存区域；
- 使用 `memcmp` 比较指定数量的字节；
- 区分内存函数和依赖 `\0` 的字符串函数。

## 1. 它们不只处理字符串

这些函数也声明在 `<string.h>` 中，但它们接收的是地址和字节数量：

```c
unsigned char source[4] = {1, 2, 3, 4};
unsigned char copy[4];

memset(copy, 0, sizeof copy);
memcpy(copy, source, sizeof source);
int same = memcmp(copy, source, sizeof source) == 0;
```

它们不会自动寻找 `\0`。第三个参数决定处理多少字节。

## 2. 三个函数的区别

- `memset(destination, value, count)`：把目标区域的每个字节设为 `value` 的低 8 位；
- `memcpy(destination, source, count)`：复制 `count` 个字节，源和目标不应重叠；
- `memcmp(left, right, count)`：比较前 `count` 个字节，返回 0 表示相等。

`memset` 不是“把数组中的每个 int 设置成任意整数”的通用函数。例如把 `int` 数组全部设置为 1，得到的通常不是每个元素都等于整数 1。

## 3. 完整示例

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned char source[4] = {1, 2, 3, 4};
    unsigned char copy[4];

    memset(copy, 0, sizeof copy);
    memcpy(copy, source, sizeof source);

    int same = memcmp(copy, source, sizeof source) == 0;

    printf("copy: ");
    for (size_t i = 0; i < sizeof copy; i++) {
        printf("%02x ", (unsigned int) copy[i]);
    }
    printf("\n");
    printf("same = %s\n", same ? "yes" : "no");

    return 0;
}
```

## 重叠区域的边界

`memcpy` 的源和目标区域重叠时，结果不可靠；需要处理重叠区域时应学习 `memmove`。本课只使用不重叠的数组。

## 挖空任务

1. 完成 `memset` 的三个实参；
2. 完成 `memcpy` 的三个实参；
3. 完成 `memcmp` 的三个实参；
4. 修改源数组，观察复制结果和比较结果；
5. 将 `memcmp` 的字节数量改小，解释为什么比较结果可能改变；
6. 思考为什么 `memset` 不能直接用来填充任意整数数组值。

## 自测题

1. 内存函数的第三个参数表示什么？
2. `memcpy` 为什么要求源和目标不重叠？
3. `memcmp` 返回 0 表示什么？
4. `memset(copy, 0, sizeof copy)` 做了什么？
5. 为什么内存函数不需要字符串结尾的 `\0`？

## 验收标准

- [ ] 能正确包含 `<string.h>`；
- [ ] 能完成三种内存函数调用；
- [ ] 能说明字节数量和数组容量的关系；
- [ ] 能指出 `memcpy` 处理重叠区域的限制。


