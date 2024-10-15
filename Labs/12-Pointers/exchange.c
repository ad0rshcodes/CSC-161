#include <stdio.h>

void exchange(double *p, double *q)
{
    double temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    double a = 543.21, b = 123.45;

    printf("Before exchange: a = %.2f, b = %.2f\n", a, b);

    exchange(&a, &b);

    printf("After exchange: a = %.2f, b = %.2f\n", a, b);

    return 0;
}
