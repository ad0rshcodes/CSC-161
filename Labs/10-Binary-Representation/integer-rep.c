/* This allows the user to set or modify short and long integers and then 
   examine the results in both decimal and binary format.  
       
   Programmer:  Henry Walker, Grinnell College
   Written in C by Henry Walker (January 28, 2005)
   Last revised by Henry Walker (January 30, 2005)
   print_binary revised by Jerod Weinman (January 4, 2019)
*/

#include <stdio.h>

void
print_binary (int digits, int number);

int
main (void)
{ 
  short short_int = 1;
  int   inte = 1;
  int number;
  char option;

  printf ("\n");
  printf ("This program allows experimentation with different sizes of integers\n\n");
  printf ("Initial integer values:           decimal                       binary\n");
  printf ("   Short (16-bit) integer:%13hd                   ", short_int);
  print_binary (16, short_int);
  printf ("\n");
  printf (" Regular (32-bit) integer:%13d   ", inte);
  print_binary (32, inte);
  printf ("\n\n");

  while (1) 
    {
      printf ("Menu Options\n");
      printf ("  I - initialize each number to a value you have entered\n");
      printf ("  A - add 1 to each integer\n");
      printf ("  S - subtract 1 from each number\n");
      printf ("  M - multiple each number by 2\n");
      printf ("  D - divide each number by 2\n");
      printf ("  Q - Quit\n");
      printf ("Enter option:  ");
      scanf(" %c", &option);

      switch (option)
        {
        case 'i':
        case 'I':
          printf ("   Enter value that will be assigned to each integer:  ");
          scanf ("%d", &number);
          short_int = (short) number;
          inte      = number;
          break;
        case 'a':
        case 'A':
          short_int += (short) 1;
          inte      += 1;
          break;
        case 's':
        case 'S':
          short_int -= (short) 1;
          inte      -= 1;
          break;
        case 'm':
        case 'M':
          short_int *= (short) 2;
          inte      *= 2;
          break;
        case 'd':
        case 'D':
          short_int /= (short) 2;
          inte      /= 2;
          break;
        case 'q':
        case 'Q':
          printf ("Program terminated\n");
          return 0;
          break;
        default: printf ("Unrecognized option -- please try again\n");
          continue;
        } // switch
      printf ("Resulting integer values          decimal                       binary\n");
      printf ("   Short (16-bit) integer:%13hd                   ", short_int);
      print_binary (16, short_int);
      printf ("\n");
      printf (" Regular (32-bit) integer:%13d   ", inte);
      print_binary (32, inte);
      printf ("\n\n");

    } // while(1)
} // main

void
print_binary (int digits, int number)
{
  /* this function prints the bit representation of number, assuming that
     digits gives the number of bits in the original declaration of number
  
     when called with short ints, digits should be 15 (at least on Pentium 4
     machines) when called with regular ints, digits should be 32
  */
  for (int position = digits-1 ; position>= 0 ; position--)
    printf ("%X", (number>>position) & 1 );
} // print_binary

// Every time we run our case "a" where we add one, not only do we represent
// the number traditionally, but it also breaks out and calls the print-
// binary function.

// 12 in binary is stored as 1100. When we multiply it by 2 repeatedly, it
// "shifts" the number over by two digits in base two. 24 can be represented
// with 2^4 and 2^3, and so on.

// At 10 digit numbers, the 16 bit binary representation overflowed. However,
// the digits of 16 bits and the ending digits of 32 bits are the same.
// The ones and 0s line up.
// binary. This happens even if both overflow for 15 and 20 digits.

//4. The behavior is similar, where the binary representation is correct,
// but now there's a sign in front for whether it's positive or negative.
// We also don't put all the zeros in front for the scheme program since
// the space is variable and depends on input size.

//5. Both convert to a similar binary representation (which they should).
// Scheme lacks the "wrap around" option, it has a recursive function to
// represent the binary for the number, so it won't overflow. However, this
// means we can't necessarily easily see the 16bit and 32bit representations.
