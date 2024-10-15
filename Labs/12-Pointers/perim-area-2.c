/* program to compute the perimeter and area of a rectangle */

#include <stdio.h>

// compute the perimeter and area of a rectangle, given the lengths of the two sides
void compute(double side1, double side2, double *perimeter, double *area)
{
  double lengthPlusWidth = side1 + side2;

  // Print memory addresses and values inside compute
  printf("parameter side1:           location: %p, value: %lf\n", (void *)&side1, side1);
  printf("parameter side2:           location: %p, value: %lf\n", (void *)&side2, side2);
  printf("local lengthPlusWidth:     location: %p, value: %lf\n", (void *)&lengthPlusWidth, lengthPlusWidth);

  // For pointers, print the pointer's address, its value, and the value it points to
  printf("parameter perimeter:       location: %p, value (pointer): %p, dereferenced value: %lf\n", (void *)&perimeter, (void *)perimeter, *perimeter);
  printf("parameter area:            location: %p, value (pointer): %p, dereferenced value: %lf\n", (void *)&area, (void *)area, *area);

  // Calculate perimeter and area
  *perimeter = 2.0 * lengthPlusWidth;
  *area = side1 * side2;
}

// demonstrate pointer passing by calling compute and displaying results
int main()
{
  // declare variables
  double length = 5.0;
  double width = 7.0;
  double perimeter;
  double area;

  // Print initial memory addresses and values in main
  printf("variable length:           location: %p, value: %lf\n", (void *)&length, length);
  printf("variable width:            location: %p, value: %lf\n", (void *)&width, width);
  printf("variable perimeter:        location: %p, value: (undefined before compute call)\n", (void *)&perimeter);
  printf("variable area:             location: %p, value: (undefined before compute call)\n", (void *)&area);

  // print header
  printf("working with a rectangle of width %lf and length %lf\n", width, length);

  // compute desired quantities
  compute(length, width, &perimeter, &area);

  // print results and memory addresses
  printf("the rectangle's perimeter is %lf\n", perimeter);
  printf("the rectangle's area is %lf\n", area);
  printf("variable perimeter:        location: %p, value: %lf\n", (void *)&perimeter, perimeter);
  printf("variable area:             location: %p, value: %lf\n", (void *)&area, area);

  return 0;
}
