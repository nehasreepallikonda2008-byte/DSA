#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
    node->left = NULL;
    node->right = NULL;
    return node;
}

static Node *insert(Node *root, int value)
{
    if (root == NULL)
        return create_node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

static void inorder(const Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

static void preorder(const Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

static void postorder(const Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

static void free_tree(Node *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int count = (int)(sizeof(values) / sizeof(values[0]));
    Node *root = NULL;
    int i;

    for (i = 0; i < count; i++)
        root = insert(root, values[i]);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
