#include <stdio.h>

int main(void)
{
    int values[] = {64, 25, 12, 22, 11};
    int count = (int)(sizeof(values) / sizeof(values[0]));
    int i, j;

    for (i = 0; i < count - 1; i++)
    {
        int minimum = i;

        for (j = i + 1; j < count; j++)
        {
            if (values[j] < values[minimum])
                minimum = j;
        }

        if (minimum != i)
        {
            int temp = values[i];
            values[i] = values[minimum];
            values[minimum] = temp;
        }
    }

    printf("Sorted array (selection sort): ");
    for (i = 0; i < count; i++)
        printf("%d ", values[i]);
    printf("\n");

    return 0;
}
