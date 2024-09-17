/*
 * lab: Basic Types
 *
 * \authors: Adarsh Sharma and Michael Getsos
 * C. 1
 */

#include <stdio.h>

int main()
{

  // C - 1 Solution

  char inputChar;

  printf("Enter a Character: ");
  inputChar = getchar();

  if (inputChar > 96 && inputChar < 123)
  {
    printf("Your character is lowercase. \n");
  }
  else if (inputChar > 64 && inputChar < 91)
  {
    printf("Your character is uppercase. \n");
  }
  else
  {
    printf("Your character is not a letter. \n");
  }
  return 0;
}
