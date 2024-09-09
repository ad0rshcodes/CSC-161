/**
 * A simple program to calculate the area and circumfrence of a circle
 * 
 * \authors Judd Brau and Adarsh Sharma
 * \acknowledgements Used this file as a starting template - https://eikmeier.sites.grinnell.edu/csc-161-fall-2024/labs/elementary-c/quarts.c
*/

// This line pulls in standard library functions for input and output
#include <stdio.h>

// The main function is the entry point of your function
int main() {
  // Print an opening statement
  printf("This program calculates a circles area and circumference from its radius\n");

  //Initial values and constants
  int radius = 5;
  float pi = 3.1415;

  //calculates area and circumference
  float area = radius * radius * pi;
  float circumference  = 2 * radius * pi;

  
  // Print the result
  printf("Radius: %d  Area: %.2f  Circumference: %.2f\n", radius, area, circumference);

  // Leave the program. Returning the value 0 means there were no errors.
  return 0;
}
