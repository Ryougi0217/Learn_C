#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

static Point make_point(int x, int y)
{
    Point point = /* TODO：初始化 point */;
    /* TODO：按值返回 point */
}

int main(void)
{
    Point point = make_point(3, 4);

    printf("(%d, %d)\n", point.x, point.y);
    return 0;
}

