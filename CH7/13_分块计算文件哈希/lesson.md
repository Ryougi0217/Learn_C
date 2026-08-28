# 第 13 课：分块计算文件哈希

## 学习目标

按固定大小分块读取文件，计算一个非加密的 FNV-1a 校验值。

## 核心概念

- 分块读取避免一次性把整个文件放进内存。
- 每轮处理 `fread` 实际返回的字节数。
- FNV-1a 适合教学中的快速校验，不是密码学哈希。
- 读取错误和正常 EOF 必须区分。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

static int hash_file(const char *path, uint64_t *result)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return 0;
    }

    uint64_t hash = UINT64_C(14695981039346656037);
    unsigned char buffer[4096];
    size_t count;

    while ((count = fread(buffer, 1, sizeof buffer, file)) > 0) {
        for (size_t i = 0; i < count; i++) {
            hash ^= buffer[i];
            hash *= UINT64_C(1099511628211);
        }
    }

    if (ferror(file)) {
        fclose(file);
        return 0;
    }

    fclose(file);
    *result = hash;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    uint64_t hash;
    if (!hash_file(argv[1], &hash)) {
        return 1;
    }

    printf("fnv1a = %016" PRIx64 "\n", hash);
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的分块读取循环。
2. 确认空文件也能得到确定的初始哈希值。
3. 修改文件一个字节，比较哈希是否变化。
4. 说明为什么这个算法不能替代密码学哈希。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

