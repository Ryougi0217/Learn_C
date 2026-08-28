#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static int remove_first(Node **head, int target)
{
    Node **link = head;

    while (/* TODO：link 指向的节点存在 */) {
        if (/* TODO：当前节点匹配 */) {
            Node *removed = *link;
            /* TODO：让 link 跳过 removed */
            /* TODO：释放 removed */
            return 1;
        }
        /* TODO：让 link 指向下一个 next 成员的地址 */
    }

    return 0;
}

int main(void)
{
    Node *first = malloc(sizeof *first);
    Node *second = malloc(sizeof *second);

    if (first == NULL || second == NULL) {
        free(first);
        free(second);
        return 1;
    }

    first->value = 10;
    first->next = second;
    second->value = 20;
    second->next = NULL;

    remove_first(&first, 10);
    printf("head = %d\n", first->value);

    free(first);
    return 0;
}

