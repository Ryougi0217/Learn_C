#include <stdio.h>

typedef struct
{
    /* TODO：声明 x 和 y */
} Point;

typedef enum
{
    /* TODO：声明三种颜色 */
} Color;

int main(void)
{
    Point point = /* TODO：初始化点 */;
    Color color = /* TODO：选择颜色 */;

    printf("point = (%d, %d)\n", point.x, point.y);
    printf("color number = %d\n", color);
    return 0;
}

