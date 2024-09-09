/* windchill.c
 *
 * Author: Adarsh Sharma, Judd Brau
 * Date: June 20, 2022
 * Revised: September 9, 2024
 * Purpose: to calculate the windchill based on two inputs:
 *		temperature (Fahrenheit) assumed to be an integer
 *      windspeed (miles per hour) assumed to be an integer
 *		forumula:  Twc = F - (W * 0.7)
 *      forumula from  Tom Skilling at the Chicago Tribune
 */
 
#include <stdio.h>

int main(void) {

  // _____ Part D _____

  // Initial values
  int a, b, c;

  // User input
  printf("Please give side a: ");
  scanf("%d", &a);

  printf("Please give side b: ");
  scanf("%d", &b);
  
  printf("Please give side c: ");
  scanf("%d", &c);

  
  //What kind of Triangle a, b, and c are
  if (a <= 0 || b <= 0 || c <= 0) {
    printf("Invalid input\n");
  }
  else if (a + b < c || a + c < b || b + c < a)
    printf("Not a triangle\n");
  else if (a != b && b != c && a != c)
    printf("Scalene\n");
  else if ((a == b) && (b == c))
    printf("Equilateral triangle\n");
  else
    printf("Isosceles\n");



  // _____ Part F _____
  // int x;

  // printf("enter the value: ");
  // scanf ("%d", &x);
  // printf("%d\n", x);

  // if (-2 <= x && x <= 2) {
  //   printf("TRUE!\n");
  // } else {
  //   printf("False\n");
  // }
}
