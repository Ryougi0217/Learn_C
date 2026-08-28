# 第 12 课：常见文件签名识别

## 学习目标

根据文件开头的魔数识别 PNG、GIF、PDF 和 ELF 等常见格式。

## 核心概念

- 文件扩展名来自名称，文件签名来自内容。
- 签名判断必须先确认实际读取长度足够。
- 识别结果是初步线索，不等于完整格式验证。
- 不认识的文件应报告 unknown，而不是强行归类。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>
#include <string.h>

static const char *detect_signature(const unsigned char *data,
                                    size_t count)
{
    static const unsigned char png[] = {
        0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A
    };
    static const unsigned char gif[] = {'G', 'I', 'F', '8'};

    if (count >= sizeof png && memcmp(data, png, sizeof png) == 0) {
        return "PNG";
    }
    if (count >= sizeof gif && memcmp(data, gif, sizeof gif) == 0) {
        return "GIF";
    }
    if (count >= 4 && memcmp(data, "%PDF", 4) == 0) {
        return "PDF";
    }
    if (count >= 4
        && data[0] == 0x7F
        && data[1] == 'E'
        && data[2] == 'L'
        && data[3] == 'F') {
        return "ELF";
    }

    return "unknown";
}

int main(void)
{
    const unsigned char data[] = {0x7F, 'E', 'L', 'F'};

    printf("format = %s\n",
           detect_signature(data, sizeof data));
    return 0;
}
```

## 练习任务

1. 完成 `practice.c` 中的签名比较函数。
2. 加入 ZIP 签名 `PK\\x03\\x04`。
3. 测试数据长度不足时是否会越界读取。
4. 解释为什么先检查长度，再调用 `memcmp`。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际编译过完整示例。
- [ ] 我手写了练习脚本中的关键部分。
- [ ] 我检查过文件操作的失败返回值。

