#include <stdio.h>

#define CAPACITY 5

int main(void)
{
    int queue[CAPACITY];
    int front = 0;
    int rear = -1;
    int values[] = {10, 20, 30};
    int i;

    for (i = 0; i < 3; i++)
        queue[++rear] = values[i];

    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");

    printf("Dequeued element: %d\n", queue[front++]);

    printf("Queue after dequeue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");

    return 0;
}
