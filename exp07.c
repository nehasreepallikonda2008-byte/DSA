#include <stdio.h>

int main(void)
{
    int values[] = {64, 34, 25, 12, 22, 11, 90};
    int count = (int)(sizeof(values) / sizeof(values[0]));
    int i, j;

    for (i = 0; i < count - 1; i++)
    {
        int swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }

    printf("Sorted array (bubble sort): ");
    for (i = 0; i < count; i++)
        printf("%d ", values[i]);
    printf("\n");

    return 0;
}
