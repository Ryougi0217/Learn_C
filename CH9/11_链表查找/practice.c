#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static const Node *find_node(const Node *head, int target)
{
    while (/* TODO：当前节点非空 */) {
        if (/* TODO：当前值等于 target */) {
            return /* TODO：返回当前节点 */;
        }
        /* TODO：移动 head */
    }

    return NULL;
}

int main(void)
{
    Node third = {30, NULL};
    Node second = {20, &third};
    Node first = {10, &second};

    const Node *found = find_node(&first, 20);
    printf("%s\n", found == NULL ? "missing" : "found");
    return 0;
}

