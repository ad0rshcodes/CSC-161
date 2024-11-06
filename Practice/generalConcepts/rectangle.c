/*
Calculate the area of a rectangle:
    1. by using the given hardcoded values
    2. By taking input from the user
*/

#include <stdio.h>

int main()
{
    // using hard coded inputs

    double l = 56.3;
    double b = 72.4;

    double area = l * b;

    printf("The area of the reactangle is %f\n", area);

    // Using input given by the user

    double c;
    double d;

    printf("Enter the length of rectangle: ");
    scanf("%lf", &c);

    printf("Enter the breath of rectangle: ");
    scanf("%lf", &d);

    printf("The area of the rectangle is: %lf", c * d);

    return 0;
}