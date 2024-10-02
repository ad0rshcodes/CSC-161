/* This program allows the user to set a memory word to any desired bit pattern,
   which may be specified either bit by bit, or by giving a decimal or 
   hexadecimal numeral designating an integer, or by giving a decimal
   numeral designating a float.  The bit pattern is then displayed in
   five different formats:  
       unsigned binary numeral, 
       unsigned hexadecimal numeral, 
       signed decimal numeral (as for int), and 
       floating-point decimal numeral (as for int).
       
   Programmer:  Henry Walker, Grinnell College
   Edited by Finn and Adarsh
   Adapted for Sun Modula-2 by John Stone, grinnell College (Sept. 2, 1990)
   Rewritten in Pascal by Henry Walker (August 16, 1994)
   Rewritten in C by Henry Walker (August 29, 2001)
   printBitGroups revised by Jerod Weinman (January 4, 2019)
*/

#include <stdio.h>

union DATA {int integer; float real;};

typedef union DATA data;

void
printBitGroups (data d, int bitGroups);

int
main (void) 
{
  
  data d;
  char option;
  int toggleBit;

  d.integer = 0;

  printf("\n");
  printf("This program allows experimentation with the bit representations\n");
  printf("  of integers and floating point numbers\n\n");

  while (1) {
    printf("Menu Options\n");
    printf("  0 - Set word to all zeros\n");
    printf("  1 - Set word to all ones\n");
    printf("  B - Toggle given bit\n");
    printf("  F - Specify floating point number\n");
    printf("  I - Specify integer\n");
    printf("  Q - Quit\n");
    printf("Enter option:  ");
    
    scanf(" %c", &option);
    
    switch (option) {
    case '0':
      d.integer = 0;
      break;
    case '1':
      d.integer = -1;
      break;
    case 'b':
    case 'B':
      printf("  Enter which bit to toggle (31..0):  ");
      scanf("%d", &toggleBit);
      d.integer = d.integer ^ (1 << toggleBit);
      break;
    case 'f':
    case 'F':
      printf("  Enter real number:  ");
      scanf("%f", &d.real);
      break;
    case 'i':
    case 'I':
      printf("  Enter integer:  ");
      scanf("%d", &d.integer);
      break;
    case 'q':
    case 'Q':
      printf("Program terminated\n");
      return 0;
      break;
    case 's':
    case 'S':
      /* no op */
      break;
    default:
      printf("Unrecognized option -- please try again\n");
      continue;
    } // switch

    printf("\n");
    printf("     Binary Form:  ");
    printBitGroups(d, 1);
    printf("Hexadecimal Form:  ");
    printBitGroups (d, 4);
    printf("    Integer Form:  %d\n", d.integer);
    printf("      Float Form:  %15.10f\n\n", d.real);
    
  } // while(1)
} // main


void
printBitGroups (data d, int bitGroups) 
{
  int value = d.integer;
  int mask = 0;
  int iterations = 32 / bitGroups;
  int a[iterations];
  int i;

  for (i = 0; i < bitGroups; i++) 
    mask = 1 | (mask << 1);

  for (i = iterations-1; i >= 0; i--) 
    printf ("%X", (value >> (bitGroups*i)) & mask);
  printf ("\n");
} // printBitGroups




/// Answers for Exercise 1
/**
1.
   1.0: 0/1  1111111 00000....
   2.0: 0/1        1 00000....         
   3.0: 0/1 10000000 10000....
   6.0: 0/1 10000001 10000....
   9.0: 0/1 10000010 00100....

2.
   The first bit is the sign bit.
   After the first sign bit and the following 8 exponent bit.
   After the first bit aka sign bit is exponent.
   127 is the bias accounted for in the storage of exponents.

3. 
   Binary Form:  00111101110011001100110011001101
   Float Form:     0.1000000015

   It differes as the float form aren't the same anymore since we need a lot more storage to store 0.1.

   
   
*/
