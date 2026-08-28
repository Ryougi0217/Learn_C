# 第 16 课：动态内存与 Sanitizer 验收

本课不额外提供脚本。请使用前面课程的练习完成动态内存验收。

## 概念验收

1. 栈对象和堆对象的生命周期有什么区别？
2. `malloc`、`calloc` 和 `realloc` 的返回值分别如何检查？
3. 为什么 `realloc` 的结果应该先保存到临时指针？
4. `count` 和 `capacity` 分别表示什么？
5. 动态字符串为什么必须为 `\0` 多申请一个字节？
6. 什么是内存所有权？
7. 什么是内存泄漏、重复释放和释放后使用？
8. 释放后把指针置为 `NULL` 能解决哪些问题，不能解决哪些问题？

## 操作验收

先运行一个默认安全脚本：

```sh
gcc -std=c17 -Wall -Wextra -Wconversion -pedantic \
    ../05_free/practice.c -o free_demo
./free_demo
```

再编译诊断版本：

```sh
gcc -std=c17 -Wall -Wextra -pedantic -g -O0 \
    -fsanitize=address,undefined,leak \
    ../12_内存泄漏/practice.c -DLEAK_DEMO -o leak_demo
./leak_demo
```

还要分别观察第 13 课的释放后使用风险。

## 代码验收

- [ ] 所有成功申请都有对应释放。
- [ ] 所有申请失败路径都不会解引用无效指针。
- [ ] 所有扩容都使用临时指针并保留失败时的原指针。
- [ ] 动态数组维护了 `count <= capacity`。
- [ ] 动态字符串包含终止符空间。
- [ ] 我实际看过一次 Sanitizer 或 LeakSanitizer 报告。
- [ ] 我能画出一个动态对象从申请到释放的生命周期。

