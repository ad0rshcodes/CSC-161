/**
 * An example program that creates and accesses an array of double values.
 * 
 * \authors Grinnell College Computer Science Faculty & Adarsh Sharma & Michael Getsos
 */

#include <stdio.h>

// Number of elements to be processed in array
#define LENGTH 12

int main() {
  // Create an array of LENGTH numbers
  double numbers[LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

  // Initialize values for sum, min, and max
  double sum = numbers[0];
  double min = numbers[0];
  double max = numbers[0];
  
  // Loop over the array, skipping over the first element
  for (int i = 1; i < LENGTH; i++) { 
    // Update maximum value
    if(numbers[i] > max) {
      max = numbers[i];
    }

    // Update minimum value
    if(numbers[i] < min) {
      min = numbers[i];
    }

    // Update sum
    sum += numbers[i];
  }

  // Print results
  printf("Maximum: %.2f\n", max);
  printf("Minimum: %.2f\n", min);
  printf("Average: %.2f\n\n", sum/LENGTH);
  
  // Print the array contents
  printf("Array Contents:\n");
  for(int i = 0; i < (LENGTH+4); i++) {
    printf("numbers[%d] = %.1lf\n", i, numbers[i]);
  }
  
  return 0;

  // 1. we get 5 first indeces
  // 2. array of 12 elements; last two are 0
  // 3. we expected an error or for it to loop from the back, but we got numbers[-1]=39.0 which is seemingly unrelated.

  // 4.Predict out-of-bound error. 

  
}
