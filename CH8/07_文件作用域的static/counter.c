#include "counter.h"

/* TODO：把模块内部状态限制在本文件 */
int current;

/* TODO：把辅助函数限制在本文件 */
void increment(void)
{
    current++;
}

int counter_next(void)
{
    increment();
    return current;
}

