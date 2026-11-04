#include<stdio.h>

#define MAX_ELEMENTS 100

static void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

static void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

static void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

static void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

static void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main(void)
{
    int n;
    int choice;
    int arr[MAX_ELEMENTS];

    printf("Enter number of elements (0-%d): ", MAX_ELEMENTS);
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX_ELEMENTS)
    {
        fprintf(stderr, "Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Invalid element.\n");
            return 1;
        }
    }

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Heap Sort\nEnter choice: ");
    if (scanf("%d", &choice) != 1)
    {
        fprintf(stderr, "Invalid choice.\n");
        return 1;
    }

    switch (choice)
    {
    case 1:
        bubble_sort(arr, n);
        break;
    case 2:
        selection_sort(arr, n);
        break;
    case 3:
        heap_sort(arr, n);
        break;
    default:
        fprintf(stderr, "Invalid choice.\n");
        return 1;
    }

    printf("Sorted array: ");
    print_array(arr, n);
    return 0;
}
