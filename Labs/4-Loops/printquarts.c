/*
 * lab: Loops
 *
 * \authors: Adarsh Sharma and Michael Getsos
 * A. 1-2
 */

#include <stdio.h>

int main()
{

  // Using For Loop
  printf("Table of quarts and liter equivalents\n");
  printf("Quarts         Liters\n");
  for (int i = 1; i <= 12; i++)
  {
    printf("  %d            %.4f\n", i, (0.9463 * i));
  }

  // Using While Loop
  printf("Table of quarts and liter equivalents\n");
  printf("Quarts         Liters\n");
  int i = 1;
  while (i < 13)
  {
    printf("  %d            %.4f\n", i, (0.9463 * i));
    i++;
  }

  return 0;
}
