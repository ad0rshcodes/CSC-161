/*
 * lab: Basic Types
 *
 * \authors: Adarsh Sharma and Michael Getsos
 * B. 1-2
 */

#include <stdio.h>

int main()
{

  int i = 9;
  double j = i / 2;
  double k = (double)i / 2;
  int l = k * 2;
  int m = (int)k * 2;
  int n = 1000;
  char o = n;
  int p = (char)n;

  printf("i=%d, j=%lf, k=%lf, l=%d, m=%d, n=%d, o=%d, p=%d\n", i, j, k, l, m, n, o, p);

  // Prediction: i=9, j=4.0, k=4.5, l=9, m=8, n=1000, o=~104, p=104
  // Result: everything was correct we incorrectly "wrapped" o and p, but we did correctly predict that they would be the same. Since we don't know binary operations we couldn't accurately predict the results.

  return 0;
}
