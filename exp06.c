#include <stdio.h>

int main(void)
{
    int values[] = {5, 12, 18, 23, 31, 42, 56};
    int count = (int)(sizeof(values) / sizeof(values[0]));
    int target = 31;
    int low = 0;
    int high = count - 1;

    while (low <= high)
    {
        int middle = low + (high - low) / 2;

        if (values[middle] == target)
        {
            printf("%d found at position %d.\n", target, middle + 1);
            return 0;
        }

        if (values[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }

    printf("%d was not found.\n", target);
    return 0;
}
