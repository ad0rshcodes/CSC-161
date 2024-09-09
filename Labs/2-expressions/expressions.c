/**
 * A simple program to convert a number of quarts to liters
 * 
 * \authors Judd Brau and Adarsh Sharma
*/

#include <stdio.h>

int main(void) {

// ______ Part A _______  
  
/**
 * a=5, b=6, c=0, d=1, e=1, f=1
*/
  int a = 5;
  int b = 6;
  int c = a / b;
  int d = b / a;
  int e = (a + b) / 10;
  int f = (a + b) % 10;
  printf("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d\n", a, b, c, d, e, f);

// ______ Part B _______
/**
 * g = 18, h = 60, i = 7
*/
int g = 5 + 4 * 3 + 1;
int h = 50 / 4 * 10 / 2;
int i = 19 % 3 * 9 - 2;
printf("g=%d, h=%d, i=%d\n", g, h, i);

//int g = 5 + (4 * 3) + 1;
// int h = ((50 / 4) * (10 / 2));
// int i = ((19 % 3) * 9) - 2;
//printf("g=%d, h=%d, i=%d\n", g, h, i);


// ______ Part C _______
/*
 * j=2 k=2 l=8
 */
 int j = 1;
int k = ++j;
int l = (k = j) * 4;
printf("j=%d, k=%d, l=%d\n", j, k, l);

 //j=4 k=4 l=2
 j *= k;//j=4
 k++;//k=3
 l /= 4; //l=2
printf("j=%d, k=%d, l=%d\n", j, ++k, l++);
}

/*
  Difference is that the prefix increments first, then returns the value, whereas the postfix returns the value stored in memory then increments it.
  
            \/ increments
 x++ => x   ++
        ^ returns value
 */
