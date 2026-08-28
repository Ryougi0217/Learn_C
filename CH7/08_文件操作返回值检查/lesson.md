# 第 8 课：文件操作返回值检查

## 学习目标

把打开、读取、写入、定位和关闭失败都纳入程序控制流，写出一个失败时也能正确清理资源的文件复制函数。

## 核心概念

- 文件操作失败可能来自路径、权限、磁盘空间或数据损坏。
- 每个库调用都有对应的返回值约定。
- `perror` 可以把当前错误原因打印到 `stderr`。
- 失败清理路径也要关闭已经成功打开的文件。
- 关闭多个资源时，不要用会短路的表达式跳过后续清理。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

static int copy_file(const char *source_name,
                     const char *target_name)
{
    FILE *source = fopen(source_name, "rb");
    if (source == NULL) {
        perror("source");
        return 0;
    }

    FILE *target = fopen(target_name, "wb");
    if (target == NULL) {
        perror("target");
        fclose(source);
        return 0;
    }

    unsigned char buffer[256];
    size_t count;
    int success = 1;

    while ((count = fread(buffer, 1, sizeof buffer, source)) > 0) {
        if (fwrite(buffer, 1, count, target) != count) {
            perror("write");
            success = 0;
            break;
        }
    }

    if (ferror(source)) {
        perror("read");
        success = 0;
    }

    /*
     * 两个 fclose 都要执行，不能写成：
     * fclose(source) != 0 || fclose(target) != 0
     * 因为 || 可能短路跳过第二个 fclose。
     */
    int source_close = fclose(source);
    int target_close = fclose(target);

    if (source_close != 0 || target_close != 0) {
        success = 0;
    }

    return success;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s SOURCE TARGET\n", argv[0]);
        return 2;
    }

    return copy_file(argv[1], argv[2]) ? 0 : 1;
}
```

## 练习任务

1. 完成 `practice.c` 中的安全复制函数。
2. 分别测试源文件不存在、目标无法打开和正常复制。
3. 找出所有成功打开后对应的 `fclose`。
4. 解释为什么循环结束后仍要检查 `ferror`。
5. 检查多个资源的清理代码，确认没有被 `&&` 或 `||` 短路跳过。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

