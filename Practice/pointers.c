#include <stdio.h>

void printAddress(int *i)
{
    printf("Address of a: %p", i);
    printf("Value of a: %d", *i);
}

void changeValue(int **a)
{
    **a = **a * 10;
}

int main()
{
    int a = 6;
    int *b = &a;
    int **c = &b;

    changeValue(c);
    printf("value of a: %d", **c);

    // printAddress(&a);
    // printf("Address of a: %p \n", b);
    // printf("Address of b: %p \n", c);
    // printf("Address of c: %p \n", &c);
    // printf("a: %d \n", *b);
    // printf("a: %d \n", **c);

    return 0;
}