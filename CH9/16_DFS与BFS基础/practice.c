#include <stdio.h>

#define VERTEX_COUNT 5

static void dfs(const int graph[VERTEX_COUNT][VERTEX_COUNT],
                int visited[VERTEX_COUNT],
                int vertex)
{
    /* TODO：标记并访问 vertex */

    for (int next = 0; next < VERTEX_COUNT; next++) {
        if (/* TODO：有边且未访问 */) {
            /* TODO：递归访问 next */
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

    /* TODO：把 start 入队并标记 */

    while (/* TODO：队列非空 */) {
        int vertex = /* TODO：取出队首 */;

        printf("%d ", vertex);

        for (int next = 0; next < VERTEX_COUNT; next++) {
            if (/* TODO：有边且未访问 */) {
                /* TODO：标记并入队 */
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

