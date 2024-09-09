/**
 * A simple program to convert a number of quarts to liters
 * 
 * \authors Judd Brau and Adarsh Sharma
*/

// This line pulls in standard library functions for input and output
#include <stdio.h>

// The main function is the entry point of your function
int main() {
  // Print an opening statement
  printf("This program converts a number of quarts to liters\n");

  // Declare a variable called quarts and give it a value
  int quarts = 2;

  // Declare a variable called liters. This is a float rather than an integer so it can represent a real number (approximately)
  float liters;

  // Convert from quarts to liters by dividing. Save that result to liters
  liters = quarts / 1.05669;

  // Print the result
  printf("%d quarts = %f liters\n", quarts, liters);

  // Leave the program. Returning the value 0 means there were no errors.
  return 0;
}




