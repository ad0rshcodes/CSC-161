#include <stdio.h>

int fibonacci(int n);

int main()
{
    printf("%d", fibonacci(1));
    printf("%d", fibonacci(2));
    printf("%d", fibonacci(3));
    printf("%d", fibonacci(4));
    printf("%d", fibonacci(5));

    return 0;
}

int fibonacci(int n)
{

    // base case is 1

    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}