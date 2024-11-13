#include <stdio.h>
#include <stdbool.h>

// #define varia "Adarsh"

void arrChange(int *arr, int len)
{
    *(arr) = 96;
    *(arr + 1) = 97;
}

int main()
{

    int numArr[5] = {578};
    int num2Arr[10];
    int num3Arr[3] = {67, 76, 90};

    arrChange(num3Arr, 3);

    printf("%d\n", *(num3Arr));
    printf("%d\n", *(num3Arr + 1));
    printf("%d\n", *(num3Arr + 2));

    int a;                // 4bytes
    char b;               // 1 byte
    bool c;               // 1 byte
    double d = 69.246389; // 8 byte
    long e;               // 8 byte
    float f = 23.48f;     // 4 byte. Need to use f at the end since every decimal number is a double.
    unsigned long g;

    // printf("%0.3f \n", f);
    // printf("%lf \n", d);
    // printf("%lu \n", sizeof(g));

    // scanf("%d", &a);
    // printf("%d\n", a);
    // getchar();
    // b = getchar();
    // printf("%c \n", b);

    // a = 69;

    // int *i = &a;
    // printf("%p \n", i);
    // printf("%d \n", *(i));
    // printf("%p \n", &i);

    // int **j = &i;
    // *(i) = 78;
    // **(j) = 67;

    // *(j) = &e;
    // printf("%p \n", i);

    // i = &d;
    // printf("%p \n", i);

    // printf("%d", a);

    // // printf("%d", num3Arr[2]);

    // printf("%d \n", *(num3Arr + 2));

    // num3Arr[2] = 69;
    // printf("%d \n", numArr[0]);
    // printf("%d \n", numArr[1]);
    // printf("%d \n", numArr[2]);
    // printf("%d \n", numArr[3]);
    // printf("%d \n", varia);

    return 0;
}