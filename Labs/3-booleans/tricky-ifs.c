/*      tricky-ifs.c

	Original written by Henry Walker
	Revised: Barbara Z Johnson
        Authors: Adarsh Sharma, Judd Brau

*/

#include <stdio.h>


int main(void) {

int TEST = 0;

if (TEST)
   printf ("statement 1\n");
   printf ("statement 2\n");

if (TEST)
   {
      printf ("statement 3\n");
      printf ("statement 4\n");
   }

if (TEST)
   printf ("statement 5\n");
else
   printf ("statement 6\n");
   printf ("statement 7\n");

if (TEST)
   printf ("statement 8\n");
else
   {
      printf ("statement 9\n");
      printf ("statement 10\n");
   }

if (TEST == 1)
   printf ("statement 11\n");
else
   printf ("statement 12\n");

 
 if (TEST = 1)
  printf ("statement 13\n");
 else
  printf ("statement 14\n");
 

return 0;

}


/*
1. printf ("statement 7\n"); isn't in the scope of else block.

2. We got a different output that prior since we are comparing whether the value of TEST is 7 or not in the second to last if statements and the last if statement would always evaluate to true since it is assigning the value to TEST.

3. We get the same output as 2nd ques because TEST except 0 would still evaluate as TRUE and -23 doesn't equal 1 for the second to last if statements.

4. Since the last if statement is assigning the value, it would always results in a true. Therefore, "Statement 13" is always printed in all cases. 
*/
