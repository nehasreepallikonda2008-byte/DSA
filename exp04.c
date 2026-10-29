#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

static Node *create_node(int value)
{
    Node *node = malloc(sizeof(*node));
    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->next = NULL;
    return node;
}

static void append(Node **head, int value)
{
    Node *node = create_node(value);
    Node **current = head;

    while (*current != NULL)
        current = &(*current)->next;

    *current = node;
}

static void display(const Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

static int delete_value(Node **head, int value)
{
    Node **current = head;

    while (*current != NULL && (*current)->data != value)
        current = &(*current)->next;

    if (*current == NULL)
        return 0;

    Node *removed = *current;
    *current = removed->next;
    free(removed);
    return 1;
}

static void free_list(Node *head)
{
    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("Linked list: ");
    display(head);

    if (delete_value(&head, 20))
    {
        printf("After deleting 20: ");
        display(head);
    }

    free_list(head);
    return 0;
}
