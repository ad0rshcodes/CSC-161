/**
 * Read a message from the user, then print it back in reverse.
 * 
 * \authors Adarsh Sharma & Michael Getsos
 */

#include <stdio.h>
#define maxLength 100

int main() {

  char inpChar;

  char inptArray[0];

  for (int i = 0; i < maxLength; i++){

    inpChar = getchar();
    inptArray[i]=inpChar;
   
    if (inpChar == '\n'){
      break;
    }

    
    printf("our char: %c\n", inpChar);
    printf("Array: %s", inptArray);

  }

  // printf("Array: %s", inptArray);
  
  return 0;
}
