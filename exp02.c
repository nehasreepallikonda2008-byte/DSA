#include <stdio.h>

#define CAPACITY 5

int main(void)
{
    int stack[CAPACITY];
    int top = -1;
    int values[] = {10, 20, 30};
    int i;

    for (i = 0; i < 3; i++)
        stack[++top] = values[i];

    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");

    printf("Popped element: %d\n", stack[top--]);
    printf("Top element: %d\n", stack[top]);

    return 0;
}
