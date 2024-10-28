/* program illustrating arrays, strings, and pointers */

#include <stdio.h>

int
main (void)
{
  char first [4] = {'C', 'o', 'l', 'd'};    /* first as an array of characters */
  char second[6] = "World"; /* second as a string: char array ending with null */
  char third [16] = {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', /* third as array */
                     ' ', 'S', 'c', 'i', 'e', 'n', 'c', 'e'}; /* of characters */
  char * fourth = second;     /* fourth as a pointer to an array of characters */
  const char * fifth = "Hello";            /* fifth as a pointer to a string literal */

  // Adding const in front of fifth tells the compiler it should not be changed
  // This is good practice for string literals

  first[3] = second[3] = third[3] = 0; // Causes 1,2,3,4 to stop at 3, fifth is unaffected
  fifth[3] = 0; // Results in error "Segmentation fault"

  printf ("first 3 characters in each array\n");
  printf ("   first: %c%c%c\n",  first[0],  first[1],  first[2]); // Col
  printf ("  second: %c%c%c\n", second[0], second[1], second[2]); // Wor
  printf ("   third: %c%c%c\n",  third[0],  third[1],  third[2]); // Com
  printf ("  fourth: %c%c%c\n", fourth[0], fourth[1], fourth[2]); // Wor
  printf ("   fifth: %c%c%c\n",  fifth[0],  fifth[1],  fifth[2]); // Hel

  printf ("Variable addresses and array base addresses\n");
  printf ("   first address: %p,   array base address: %p\n", &first,  first); // Unique
  printf ("  second address: %p,   array base address: %p\n", &second, second); // Same as fourth
  printf ("   third address: %p,   array base address: %p\n", &third,  third); // Unique
  printf ("  fourth address: %p,   array base address: %p\n", &fourth, fourth); // Same as fourth
  printf ("   fifth address: %p,   array base address: %p\n", &fifth,  fifth); // Unique

  printf ("variables printed as strings\n");
  printf ("   first: %s\n", first); // Error because it doesn't end with \0 (nvm, it worked)
  printf ("  second: %s\n", second); // "World"
  printf ("   third: %s\n", third); // Error since it doesn't end with \0 (nvm, it worked)
  printf ("  fourth: %s\n", fourth); // "World"
  printf ("   fifth: %s\n", fifth); // "Hello"

  return 0;
} // main
