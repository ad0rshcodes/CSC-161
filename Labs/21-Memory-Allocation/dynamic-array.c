#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Creating a dynamic array.\n");

  // Create variables to track the array
  int* data = NULL;
  int capacity = 0;

  // Exercise D.2: Allocate space in the array
  // TODO: use realloc to request space for three integers in the array

  // Fill in some values:
  data[0] = 151;
  data[1] = 161;
  data[2] = 207;

  // Print the array:
  printf("My CS major:\n");
  for(int i=0; i<capacity; i++) {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.3: Expand the array
  // TODO: expand the array to hold ten values
  
  // Fill in more values
  data[3] = 208;
  data[4] = 213;
  data[5] = 261;
  data[6] = 301;
  data[7] = 324;
  data[8] = 341;
  data[9] = 395;

  // Print the array again to show that the original three values were preserved:
  printf("My CS major:\n");
  for(int i=0; i<capacity; i++) {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.4: Shrink the array
  // TODO: use realloc to shrink the array so it only holds nine values

  // Print the array again:
  printf("My CS major:\n");
  for(int i=0; i<capacity; i++) {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.5: Free the array
  // TODO: free the memory allocated to hold the array

  printf("All done.\n");
}
