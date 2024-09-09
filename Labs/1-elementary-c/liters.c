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
  int quarts = 10;
  int gallons = 1;
  int pints = 5;

  float totalQuarts = gallons*4 + pints/2.0 + quarts;
    
  // Declare a variable called liters. This is a float rather than an integer so it can represent a real number (approximately)
  float liters;

  // Convert from quarts to liters by dividing. Save that result to liters
  liters = totalQuarts / 1.05669;

  //printing gallons, pints and quarts
  printf("%d quarts, %d pints, %d gallons \n", quarts, pints, gallons);
  
  // Print the result
  printf("%f quarts = %f liters\n", totalQuarts, liters);

  // Leave the program. Returning the value 0 means there were no errors.
  return 0;
}
