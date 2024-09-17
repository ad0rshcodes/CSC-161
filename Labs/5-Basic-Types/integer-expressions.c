/*
 * lab: Basic Types
 *
 * \authors: Adarsh Sharma and Michael Getsos
 * A. 1-4
 */

#include <stdio.h>

int main()
{

  char a = 10;
  short b = a * 50;
  int c = b * 200;
  long d = c / 3;
  long long e = a - 11;
  printf("a=%d, b=%d, c=%d, d=%ld, e=%lld\n", a, b, c, d, e);
  // '\n', 500, 100000, 33333, -1
  // Everything was correct except for a because we thought that since its a character it will chnage it to its corresponding ascii value ('\n').

  a += c;
  b -= e;
  c = (char)c;
  printf("a=%d, b=%d, c=%d\n", a, b, c);

  // -78, 501, -88 is our prediction
  // b was correct but a and c were both off by 8. We understood how the casting was performed but made soem error when calculating in binary

  return 0;
}
