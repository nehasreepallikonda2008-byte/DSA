#include <stdio.h>

#define CAPACITY 5

int main(void)
{
    int queue[CAPACITY];
    int front = -1;
    int rear = -1;
    int i;

    int initial_values[] = {10, 20, 30};
    for (i = 0; i < 3; i++)
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % CAPACITY;
        queue[rear] = initial_values[i];
    }

    printf("Dequeued element: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % CAPACITY;

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % CAPACITY;
    queue[rear] = 40;

    printf("Circular queue: ");
    i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % CAPACITY;
    }
    printf("\n");

    return 0;
}
