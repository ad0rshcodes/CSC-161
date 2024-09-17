/*
 * lab: Basic Types
 *
 * \authors: Adarsh Sharma and Michael Getsos
 * C. 2
 */

#include <stdio.h>

int main()
{
    // C - 2 Solution

    for (int i = 0; i <= 127; i++)
    {
        printf("%d: \'%c\' \n", i, (char)i);
    }

    return 0;
}