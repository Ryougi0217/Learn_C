# 第 13 课：悬空指针与局部变量地址

## 学习目标

完成本课后，你应该能够：

1. 说明局部变量的生命周期。
2. 解释什么是悬空指针。
3. 识别“地址看起来有效，但对象已经不存在”的错误。
4. 使用输出参数，让调用者提供仍然有效的存储空间。
5. 用编译器警告和 Sanitizer 辅助发现未定义行为。

## 1. 局部变量不会永远存在

函数执行时，局部变量会被创建；函数返回后，局部变量的生命周期结束。

```c
#include <stdio.h>

static int *bad_pointer(void)
{
    int local = 42;

    return &local;  /* 返回后 local 不再存在 */
}

int main(void)
{
    int *pointer = bad_pointer();

    printf("address = %p\n", (void *)pointer);
    return 0;
}
```

这段代码的问题不是“取地址”本身，而是：

1. `local` 是 `bad_pointer` 的局部变量。
2. `bad_pointer` 返回后，`local` 的生命周期结束。
3. 返回的地址不再指向一个有效的 `int` 对象。
4. 后续解引用 `pointer` 会产生未定义行为。

即使程序暂时打印出一个数字，也不能说明代码正确。未定义行为可能表现为：

- 打印旧值；
- 打印随机值；
- 程序崩溃；
- 在另一次编译或运行中出现不同结果。

## 2. 悬空指针是什么

悬空指针（dangling pointer）是指：指针中仍保存着某个地址，但该地址对应的对象已经结束生命周期或不再可访问。

常见来源包括：

- 返回局部变量的地址；
- 保存已经释放的堆内存地址；
- 保存已经失效的数组元素地址；
- 使用临时对象结束生命周期后的地址；
- 对象已经销毁，但其他指针仍然保留旧地址。

要特别注意：

> `NULL` 检查只能判断指针是否为空，不能证明非空指针仍然有效。

例如，下面的判断不能修复悬空指针：

```c
if (pointer != NULL) {
    printf("%d\n", *pointer);
}
```

悬空指针通常是非空的，所以程序可能通过判断后仍然发生错误。

## 3. 安全方案：让调用者提供存储空间

如果函数需要“产生一个结果”，可以让调用者准备一个仍在有效生命周期内的变量，然后把它的地址传进来。

```c
#include <stdio.h>
#include <stddef.h>

static int write_value(int *destination)
{
    if (destination == NULL) {
        return 0;
    }

    *destination = 42;
    return 1;
}

int main(void)
{
    int result = 0;

    if (write_value(&result)) {
        printf("result = %d\n", result);
    } else {
        printf("destination is NULL\n");
    }

    return 0;
}
```

这里的关系是：

- `result` 由 `main` 创建；
- `result` 在整个调用期间仍然存在；
- `&result` 把它的地址传给 `write_value`；
- `write_value` 通过 `destination` 修改 `result`；
- 函数返回后，`result` 仍然有效。

这是一种常见的“输出参数”模式。

## 4. 完整示例：比较危险写法和安全写法

下面的程序默认只运行安全路径。传入 `-DTRY_DANGLING` 后，才会编译诊断分支，用于观察编译器和 Sanitizer 的提示。

```c
#include <stdio.h>

static int write_value(int *destination)
{
    if (destination == NULL) {
        return 0;
    }

    *destination = 42;
    return 1;
}

#if defined(TRY_DANGLING)
static int *make_dangling_pointer(void)
{
    int local = 42;

    return &local;
}
#endif

int main(void)
{
    int result = 0;

    if (write_value(&result)) {
        printf("safe result = %d\n", result);
    }

#if defined(TRY_DANGLING)
    int *dangling = make_dangling_pointer();

    printf("dangling address = %p\n", (void *)dangling);
    printf("dangling value = %d\n", *dangling); /* 故意保留的未定义行为 */
#else
    printf("default path does not dereference a dangling pointer\n");
#endif

    return 0;
}
```

默认编译并运行：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic practice.c -o practice
./practice
```

可以看到安全路径把 `result` 写成了 `42`，并且没有返回局部变量地址。

如果只想观察编译器对危险分支的警告：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic -DTRY_DANGLING practice.c -o dangling_demo
```

在支持 AddressSanitizer 的环境中，可以进一步使用：

```sh
gcc -std=c17 -Wall -Wextra -pedantic -DTRY_DANGLING -g -O0 \
    -fsanitize=address,undefined practice.c -o dangling_san
./dangling_san
```

这一分支是诊断练习，不是应该保留在生产代码中的写法。

## 5. 练习任务

打开同目录的 `practice.c`，先不要查看答案，完成以下任务：

### 任务 A：运行安全路径

编译并运行默认程序，确认输出中有：

- `safe result = 42`；
- 默认路径没有解引用悬空指针。

### 任务 B：观察警告

使用 `-DTRY_DANGLING` 编译，记录编译器是否提示返回局部变量地址。

### 任务 C：观察 Sanitizer

如果环境支持 Sanitizer，运行诊断分支，观察它是否指出无效访问或生命周期问题。

### 任务 D：改写接口

把“返回局部变量地址”的思路改写成输出参数：

```c
static int make_value(int *destination)
{
    /* 由你完成 */
}
```

要求：

- 成功时向调用者写入 `42`；
- 参数为空时不能解引用；
- 用返回值表示成功或失败；
- `main` 中的结果变量必须由调用者拥有。

### 任务 E：解释原因

用自己的话回答：

1. 为什么 `return &local;` 比“返回一个普通整数”危险？
2. 为什么非空检查不能保证指针有效？
3. 为什么把指针设置为 `NULL` 能避免再次误用，但不能恢复已经失效的对象？

## 本课检查点

- [ ] 我知道局部变量何时失效。
- [ ] 我能识别返回局部变量地址的代码。
- [ ] 我知道悬空指针不一定等于 `NULL`。
- [ ] 我能用输出参数替代返回局部变量地址。
- [ ] 我实际运行过编译器警告或 Sanitizer。

