#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME_LENGTH 100

int main()
{
  // First, we're going to generate a random number of names to ask for.
  // To do this well, we need to *seed* a pseudo-random number generator.
  srand(time(NULL));

  // Now generate a random number of names to ask for. We want 2–5.
  int num_names = (rand() % 4) + 2;

  // TODO: Allocate space for an array that holds `num_names` strings.
  // The result is a double pointer because it is an array of pointer values.
  char **names = (char **)malloc(num_names * sizeof(char *));
  if (names == NULL)
  {
    fprintf(stderr, "Memory allocation failed for names array.\n");
    return 1; // Exit with error
  }

  // Ask the user to enter names:
  printf("Please enter %d names.\n", num_names);
  for (int i = 0; i < num_names; i++)
  {
    // TODO: Allocate space for NAME_LENGTH characters
    names[i] = (char *)malloc(NAME_LENGTH);
    if (names[i] == NULL)
    {
      fprintf(stderr, "Memory allocation failed for name %d.\n", i + 1);
      return 1; // Exit with error
    }

    // Ask the user for a name
    printf("Enter name %d: ", i + 1);
    fflush(stdout); // Display the prompt without a newline

    // Read in the name
    fgets(names[i], NAME_LENGTH, stdin);
  }

  // Print the results:
  printf("You entered:\n");
  for (int i = 0; i < num_names; i++)
  {
    printf("  %d: %s", i + 1, names[i]);
  }

  // Free allocated memory
  for (int i = 0; i < num_names; i++)
  {
    free(names[i]); // Free each name string
  }
  free(names); // Free the array of pointers

  return 0;
}
