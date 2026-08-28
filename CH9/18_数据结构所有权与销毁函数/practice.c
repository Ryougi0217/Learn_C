#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

static int push_front(Node **head, int value)
{
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->next = *head;
    *head = node;
    return 1;
}

static void destroy_list(Node **head)
{
    if (head == NULL) {
        return;
    }

    while (*head != NULL) {
        Node *next = (*head)->next;
        free(*head);
        *head = next;
    }
}

int main(void)
{
    Node *head = NULL;

    push_front(&head, 1);
    push_front(&head, 2);
    destroy_list(&head);

    printf("head = %s\n", head == NULL ? "NULL" : "not NULL");
    return 0;
}

