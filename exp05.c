#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 25, 30, 40};
    int count = (int)(sizeof(values) / sizeof(values[0]));
    int target = 25;
    int i;

    for (i = 0; i < count; i++)
    {
        if (values[i] == target)
        {
            printf("%d found at position %d.\n", target, i + 1);
            return 0;
        }
    }

    printf("%d was not found.\n", target);
    return 0;
}
