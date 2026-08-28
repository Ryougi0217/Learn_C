# 第 16 课：DFS 与 BFS 基础

## 学习目标

在小型图上实现深度优先搜索和广度优先搜索，比较访问顺序。

## 核心概念

- DFS 沿一条路径尽量深入，常用递归或显式栈。
- BFS 逐层访问，常用队列。
- `visited` 数组防止重复访问和环路。
- 图的表示方式会影响遍历代码和复杂度。

## 完整示例

先阅读并运行下面的完整示例，再打开同目录的 `practice.c` 手写关键部分。

```c
#include <stdio.h>

#define VERTEX_COUNT 5

static void dfs(const int graph[VERTEX_COUNT][VERTEX_COUNT],
                int visited[VERTEX_COUNT],
                int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int next = 0; next < VERTEX_COUNT; next++) {
        if (graph[vertex][next] && !visited[next]) {
            dfs(graph, visited, next);
        }
    }
}

static void bfs(const int graph[VERTEX_COUNT][VERTEX_COUNT],
                int start)
{
    int queue[VERTEX_COUNT];
    int visited[VERTEX_COUNT] = {0};
    size_t head = 0;
    size_t tail = 0;

    queue[tail++] = start;
    visited[start] = 1;

    while (head < tail) {
        int vertex = queue[head++];
        printf("%d ", vertex);

        for (int next = 0; next < VERTEX_COUNT; next++) {
            if (graph[vertex][next] && !visited[next]) {
                visited[next] = 1;
                queue[tail++] = next;
            }
        }
    }
}

int main(void)
{
    const int graph[VERTEX_COUNT][VERTEX_COUNT] = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int visited[VERTEX_COUNT] = {0};

    printf("DFS: ");
    dfs(graph, visited, 0);
    printf("\nBFS: ");
    bfs(graph, 0);
    putchar('\n');
    return 0;
}
```

## 练习任务

1. 手写 DFS，补齐 visited 和递归调用。
2. 手写 BFS 的队列逻辑。
3. 增加一个孤立顶点，观察两种遍历是否访问它。
4. 解释为什么 DFS 和 BFS 都需要 visited 数组。

## 本课检查点

- [ ] 我能用自己的话解释本课的核心概念。
- [ ] 我实际运行过完整示例。
- [ ] 我手写了练习脚本中的关键函数或逻辑。
- [ ] 我测试过空数据、单元素或边界输入。

