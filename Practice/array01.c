#include <stdio.h>

int main()
{
    int arr[10];

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {

        arr[i] = 5 * (i + 1);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d \n", arr[i]);
    }

    return 0;
}