#include <stdio.h>

void changeElement(int *arr, int len)
{
    *(arr + 1) = 55;
}

int main()
{

    int a = 5;
    int b = 10;
    int c = 15;

    int arr[5] = {12, 13, 15, 17, 20};

    changeElement(arr, 5);

    printf("%d \n", *(arr + 1));
    // printf("%p \n", arr[0]);
    // printf("%p \n", &arr[0]);
    // printf("%p \n", arr + 1);
    // printf("%p \n", &arr[1]);

    return 0;
}