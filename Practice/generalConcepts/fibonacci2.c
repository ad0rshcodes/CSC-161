#include <stdio.h>

// 1, 1, 2, 3, 5

int fibonacci(int n)
{

    if (n == 2 || n == 1)
    {
        return 1;
    }
    else
    {

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{

    printf("5th: %d", fibonacci(5));

    return 0;
}