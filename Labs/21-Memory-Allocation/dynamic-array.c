#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Creating a dynamic array.\n");

  // Create variables to track the array
  int *data = NULL;
  int capacity = 0;

  // Exercise D.2: Allocate space in the array
  // TODO: use realloc to request space for three integers in the array

  capacity = 3;                                 // Set the capacity to 3
  data = realloc(data, capacity * sizeof(int)); // Allocate space for 3 integers

  // Fill in some values:
  data[0] = 151;
  data[1] = 161;
  data[2] = 207;

  // Print the array:
  printf("My CS major:\n");
  for (int i = 0; i < capacity; i++)
  {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.3: Expand the array
  // TODO: expand the array to hold ten values

  capacity = 10;                                // Update the capacity to 10
  data = realloc(data, capacity * sizeof(int)); // Expand the array to hold 10 integers
  if (data == NULL)
  {
    fprintf(stderr, "Failed to allocate memory.\n");
    return 1; // Exit if memory allocation fails
  }

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
  for (int i = 0; i < capacity; i++)
  {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.4: Shrink the array
  // TODO: use realloc to shrink the array so it only holds nine values

  capacity = 9;                                 // Update the capacity to 9
  data = realloc(data, capacity * sizeof(int)); // Shrink the array to hold 9 integers
  if (data == NULL)
  {
    fprintf(stderr, "Failed to allocate memory.\n");
    return 1; // Exit if memory allocation fails
  }

  // Print the array again:
  printf("My CS major:\n");
  for (int i = 0; i < capacity; i++)
  {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.5: Free the array
  // TODO: free the memory allocated to hold the array

  free(data);  // Free the memory allocated to hold the array
  data = NULL; // Avoid dangling pointer

  printf("All done.\n");
}
