#include <stdio.h>

int main()
{
  printf("Table of quarts and liter equivalents\n");
  printf("Quarts         Liters\n");
  for (int i = 1; i <= 12; i++)
  {
    printf("%d             %f\n", i, (0.9463 * i));
  }

  printf("Table of quarts and liter equivalents\n");
  printf("Quarts         Liters\n");
  int i = 1;
  while (i < 13)
  {
    printf("%d             %f\n", i, (0.9463 * i));
    i++;
  }

  return 0;
}
