#include <stdio.h>

int sum(int *c, int *d)
{
    return *c + *d;
}

double avg(int *c, int *d)
{
    return (*c + *d) / 2.0;
}

int main()
{
    int a;
    int b;
    printf("enter a: ");
    scanf("%d", &a);

    printf("enter b: ");
    scanf("%d", &b);

    printf("The sum of the numbers is %d and the avg is %0.0lf", sum(&a, &b), avg(&a, &b));

    return 0;
}