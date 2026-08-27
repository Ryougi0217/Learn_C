# 第 2 课：二维数组

## 本课目标

完成本课后，你应该能够：

- 声明和初始化二维数组；
- 使用行下标和列下标访问元素；
- 使用嵌套循环遍历二维数组；
- 区分行数、列数和元素数量。

## 1. 二维数组的形状

二维数组可以理解为“数组中的数组”：

```c
int board[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

它有 2 行、3 列：

- `board[0][0]` 是第一行第一列；
- `board[1][2]` 是第二行第三列；
- `board[2][0]` 超出行范围。

两个下标都从 0 开始。

## 2. 嵌套循环

遍历二维数组时，外层循环负责行，内层循环负责列：

```c
for (size_t row = 0; row < 2; row++) {
    for (size_t column = 0; column < 3; column++) {
        printf("%d ", board[row][column]);
    }
    putchar('\n');
}
```

内层循环每完成一行，外层循环才进入下一行。

## 3. 完整示例

```c
#include <stdio.h>

int main(void)
{
    int board[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    size_t rows = sizeof board / sizeof board[0];
    size_t columns = sizeof board[0] / sizeof board[0][0];

    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            printf("%d ", board[row][column]);
        }
        putchar('\n');
    }

    return 0;
}
```

这里使用了 `putchar` 输出换行。它也是标准输入输出库中的函数，但一次只输出一个字符。

## 修改/观察任务

1. 把二维数组改成 3 行 4 列；
2. 手算行数、列数和元素总数；
3. 修改程序，输出每一行的和；
4. 交换行循环和列循环，观察输出顺序；
5. 使用 Sanitizer 检查一次错误的列边界。

## 自测题

1. `int board[2][3]` 有几行几列？
2. `board[1][2]` 是第几行第几列？
3. 为什么二维数组需要两个下标？
4. 外层循环和内层循环分别负责什么？
5. `sizeof board[0] / sizeof board[0][0]` 表示什么？

## 验收标准

- [ ] 能声明和初始化二维数组；
- [ ] 能用嵌套循环遍历二维数组；
- [ ] 能正确计算行数和列数；
- [ ] 能定位一次行或列越界。

