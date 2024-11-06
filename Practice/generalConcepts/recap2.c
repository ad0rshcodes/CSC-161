#include <stdio.h>
#include <limits.h>

#define name "Adarsh";
#define func(a, b, c) ((a + b + c) > INT_MAX ? printf("Overflowing") : printf("Seems good!"))

// function prototype
int sum(int a, int b);

int main()
{
    unsigned long d;
    float e;
    double f;

    printf("Above scanfs");
    scanf("%lu", &d);

    scanf("%f", &e);
    scanf("%lf", &f);

    func(d, e, f);

    return 0;
}