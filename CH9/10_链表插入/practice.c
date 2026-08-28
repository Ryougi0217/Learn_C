#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static int push_front(Node **head, int value)
{
    Node *node = /* TODO：申请节点 */;

    if (/* TODO：申请失败 */) {
        return 0;
    }

    /* TODO：初始化 node 并连接旧 head */
    return 1;
}

static void destroy_list(Node *head)
{
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    Node *head = NULL;

    push_front(&head, 20);
    push_front(&head, 10);

    for (Node *current = head;
         current != NULL;
         current = current->next) {
        printf("%d ", current->value);
    }
    putchar('\n');

    destroy_list(head);
    return 0;
}

