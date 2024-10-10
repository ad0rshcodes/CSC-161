/**
 * HW4-Couting-Bigrams
 * Author Name: Adarsh Sharma
 * Class: CSC-161-01
 */

#include <stdio.h>

#define CHAR_COUNT 128 // No. of ASCII characters

int main()
{
  // Variable Initialization
  int bigram_count[CHAR_COUNT][CHAR_COUNT] = {0};
  int c, prev = -1;
  int total_chars = 0;
  int max_count = 0;
  int max_i = 0, max_j = 0;

  printf("Enter text:\n");

  /**
   * Loop to continue taking input until enter is pressed.
   * All inputs are stored in the 2D array 'bigram_count'
   * 'Enter' is not stored
   * */

  while ((c = getchar()) != '\n')
  {
    if (prev != -1)
    {
      bigram_count[prev][c]++;
      if (bigram_count[prev][c] > max_count)
      {
        max_count = bigram_count[prev][c];
        max_i = prev;
        max_j = c;
      }
    }
    prev = c;
    total_chars++;
  }

  /**
   * If-Else to display the final result of bigram counts.
   * Error message if the entered character numbers are less than 2.
   */

  if (total_chars < 2)
  {
    printf("Invalid input. It's too short to contain any bigrams.\n");
  }
  else
  {
    printf("\nBigram counts:\n");
    for (int i = 0; i < CHAR_COUNT; i++)
    {
      for (int j = 0; j < CHAR_COUNT; j++)
      {
        {
          if (bigram_count[i][j] > 0)
            printf("'%c%c': %d\n", i, j, bigram_count[i][j]);
        }
      }
    }

    printf("\nMost common bigram: '%c%c' (No. of times: %d)\n", max_i, max_j, max_count);
  }

  return 0;
}