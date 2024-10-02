/* Program to review a loop with floats */

#include <stdio.h>

int 
main()
{
  double inc = 1.0/10.0;
  double val = 0.0;
  double end = 1.0;
  double sum = 0.0;

  printf("loop with floats from %22.15f to %22.15f by increment %22.15f\n",
          val, end, inc);

  for(int i = 0; i<=10; i++)
    {
      sum += val;                                /* add to sum and print */
      printf("val = %22.15f;  sum = %22.15f\n", val, sum);
      
      val += inc;      /* increment val for loop test and next iteration */
    }

  printf("loop terminated with val = %22.15f;  sum = %22.15f\n", val, sum);
}
