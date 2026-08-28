#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static void print_list(const Node *head)
{
    for (const Node *current = head;
         /* TODO：当前节点非空 */;
         /* TODO：移动到下一个节点 */) {
        printf("%d ", /* TODO：当前节点的值 */);
    }
    putchar('\n');
}

int main(void)
{
    Node third = {30, NULL};
    Node second = {20, &third};
    Node first = {10, &second};

    print_list(&first);
    return 0;
}

