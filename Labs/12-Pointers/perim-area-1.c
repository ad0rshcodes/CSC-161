/* program to compute the perimeter and area of a rectangle */

#include <stdio.h>

// function to compute the perimeter of a rectangle given the lengths of the two sides
double calculate_perimeter(double side1, double side2)
{
  double lengthPlusWidth = side1 + side2;

  // Print memory addresses and values
  printf("parameter side1:  location: %p, value: %lf\n", (void *)&side1, side1);
  printf("parameter side2:  location: %p, value: %lf\n", (void *)&side2, side2);
  printf("local lengthPlusWidth:  location: %p, lengthPlusWidth: %lf\n", (void *)&lengthPlusWidth, lengthPlusWidth);

  return 2.0 * lengthPlusWidth;
}

// function to compute the area of a rectangle, given the lengths of the two sides
double calculate_area(double side1, double side2)
{
  double area = side1 * side2;

  // Print memory addresses and values
  printf("parameter side1:  location: %p, value: %lf\n", (void *)&side1, side1);
  printf("parameter side2:  location: %p, value: %lf\n", (void *)&side2, side2);
  printf("local area:       location: %p, value: %lf\n", (void *)&area, area);

  return area;
}

int main()
{
  // declare rectangle's size
  double length = 5.0;
  double width = 7.0;

  // Print initial memory addresses and values
  printf("variable length:  location: %p, value: %lf\n", (void *)&length, length);
  printf("variable width:   location: %p, value: %lf\n", (void *)&width, width);

  printf("working with a rectangle of width %lf and length %lf\n", width, length);

  double perimeter = calculate_perimeter(length, width);
  double area = calculate_area(length, width);

  printf("the rectangle's perimeter is %lf\n", perimeter);
  printf("variable perim:   location: %p, value: %lf\n", (void *)&perimeter, perimeter);
  printf("the rectangle's area is %lf\n", area);
  printf("variable area:    location: %p, value: %lf\n", (void *)&area, area);

  return 0;
}
