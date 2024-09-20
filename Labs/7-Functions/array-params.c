/**
 * A program that solves quadratic formulas.
 * C. 1-4
 * \authors Grinnell CS Faculty, Adarsh Sharma, ET Ourn
 */

#include <stdio.h>

#define LENGTH 10

int sum(const int values[], int len)
{
  // TODO: Add up the values in the values array and return the result

  int sumArray = 0;

  for (int i = 0; i < len; i++)
  {
    sumArray += values[i];
  }

  return sumArray;
}

// Add one to a value
void incrementValue(int v)
{
  v++;
}

// Add oen to every value in an array
void incrementArray(int values[], int len)
{
  for (int i = 0; i < len; i++)
  {
    values[i]++;
  }
}

int main()
{
  int values[LENGTH] = {21, 4, 18, 4, 8, 15, 16, 23, 42, 57};

  // Compute the sum and print the result
  int total = sum(values, LENGTH);
  printf("The total is %d\n", total);

  // Add one to every value in the array
  for (int i = 0; i < LENGTH; i++)
  {
    incrementValue(values[i]);
  }

  // Now compute the sum again and print the result. Make sure you try to guess the result before running this code
  total = sum(values, LENGTH);
  printf("The total is %d\n", total);

  // Try using the incrementArray function to add one to every value
  incrementArray(values, LENGTH);

  // Compute the sum one last time and print the result
  total = sum(values, LENGTH);
  printf("The total is %d\n", total);

  return 0;
}
