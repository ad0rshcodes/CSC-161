#include <stdio.h>

void make_sound(char sound[], int count)
{
  for (int i = 0; i < count; i++)
  {
    printf("%s\n", sound);
  }
}
