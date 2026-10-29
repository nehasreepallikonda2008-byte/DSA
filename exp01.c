// Implementation of Basic Array Operations
// Insertion, Deletion and Traversal

#include <stdio.h>

void insertion(int arr[], int *n)
{
    int pos, value, i;

    printf("Enter position and value: ");
    scanf("%d %d", &pos, &value);

    if (pos < 1 || pos > *n + 1 || *n >= 100)
    {
        printf("Invalid position or array is full!\n");
        return;
    }

    for (i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void deletion(int arr[], int *n)
{
    int pos, i;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    printf("Element deleted successfully.\n");
}

void traversal(int arr[], int n)
{
    int i;

    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void)
{
    int arr[100], n, i, choice;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid array element!\n");
            return 1;
        }
    }

    do
    {
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Traversal");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                insertion(arr, &n);
                break;

            case 2:
                deletion(arr, &n);
                break;

            case 3:
                traversal(arr, n);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
