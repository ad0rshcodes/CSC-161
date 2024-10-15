#include <stdio.h>

int divide(int numerator, int denominator, int *quotient, int *remainder)
{
    if (denominator == 0)
    {
        return -1; // Error: division by zero
    }

    *quotient = numerator / denominator;
    *remainder = numerator % denominator;
    return 0; // Success
}

int main()
{
    int quotient, remainder;

    // Case 1: Error (division by zero)
    if (divide(10, 0, &quotient, &remainder) == -1)
    {
        printf("Err: Division by zero\n");
    }

    // Case 2: Zero remainder
    if (divide(20, 5, &quotient, &remainder) == 0)
    {
        printf("20 / 5 = %d, remainder = %d\n", quotient, remainder);
    }

    // Case 3: Non-zero remainder
    if (divide(22, 5, &quotient, &remainder) == 0)
    {
        printf("22 / 5 = %d, remainder = %d\n", quotient, remainder);
    }

    return 0;
}
