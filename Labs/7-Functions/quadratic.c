/**
 * A program that solves quadratic formulas.
 * A. 1-3, B 1-2
 * \authors Grinnell CS Faculty, Adarsh Sharma, ET Ourn
 */

#include <stdio.h>
#include <math.h>

#define NUM_EQUATIONS 3

// Print a quadratic equation
void printEquation(double a, double b, double c)
{
  // TODO: print the equation y=ax^2+bx+c here, using values for a, b, and c
  // If a coefficient is zero, leave that term out (e.g., when c is 0, do not print +0 at the end)

  printf("y=");

  if (a == 0 && b == 0 && c == 0)
  {
    printf("0");
  }

  if (a != 0)
  {
    printf("%.1fx^2", a);
  }
  if (b != 0)
  {
    if (a != 0)
    {
      printf("+");
    }
    printf("%.1fx", b);
  }
  if (c != 0)
  {
    if (b != 0)
    {
      printf("+");
    }
    printf("%.1f", c);
  }
}

double determent(double a, double b, double c)
{
  return (sqrt(pow(b, 2) - 4 * a * c));
}

// Find one of the roots of a quadratic equation
double findFirstRoot(double a, double b, double c)
{
  // TODO: find one of the roots of a quadratic equation and return it
  double firstRoot = (-b + determent(a, b, c)) / (2 * a);
  return firstRoot;
}

// Find the second root of a quadratic equation
double findSecondRoot(double a, double b, double c)
{
  // TODO: find another one of the roots of a quadratic equation and return it
  double secondRoot = (-b - determent(a, b, c)) / (2 * a);
  return secondRoot;
}

int main()
{
  // Use a 2D array to hold coefficients for several quadratic equations
  double equations[][3] = {{1, -4, 1}, {5, 6, 1}, {3, 3, 0}, {1, -3, 0}};

  // Loop over equations to print and solve each one. This loop uses sizeof to count the number of equations (refer back to the arrays reading if this is unfamiliar)
  for (int i = 0; i < sizeof(equations) / sizeof(equations[0]); i++)
  {
    printf("Equation %d:\n", i);
    printEquation(equations[i][0], equations[i][1], equations[i][2]);
    printf(" Roots: %lf, %lf\n",
           findFirstRoot(equations[i][0], equations[i][1], equations[i][2]),
           findSecondRoot(equations[i][0], equations[i][1], equations[i][2]));

    // Print a blank line for readability
    printf("\n");
  }

  return 0;
}
