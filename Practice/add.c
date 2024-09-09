#include <stdio.h>

int main()
{
    int a;
    int b;

    printf("simple calculator \n");
    printf("Enter the first number: ");

    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Total: %d", a + b);
}