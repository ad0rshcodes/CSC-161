#include <stdio.h>

void set_max(int m, int n, int *result)
{
    if (m > n)
    {
        *result = m;
    }
    else
    {
        *result = n;
    }
}

int main()
{
    int result;

    set_max(10, 20, &result);
    printf("Max of 10 & 20: %d\n", result);

    set_max(100, 50, &result);
    printf("Max of 100 & 50: %d\n", result);

    set_max(-10, -20, &result);
    printf("Max of -10 & -20: %d\n", result);

    return 0;
}
