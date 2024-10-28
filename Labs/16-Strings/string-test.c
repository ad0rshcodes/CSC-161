#include <stdio.h>
int main(){
  
  char *baboon; // Valid because it's a pointer declaration
  char *chimpanzee = "animal"; // Valid because it's a string literal
  // char dolphin[]; // Invalid because it does not specify size of the array
  char emu[] = "animal";  // Valid
  char giraffe[8] = "animal"; // Valid
  char fox[4] = "animal"; // Valid, but may cause error due to size
  char elephant[10]; // Valid character array declaration
  // elephant = "animal"; // Invalid because its not assignable

  printf("fox: %s\n giraffe: %s\n", fox, giraffe);

  // Changing the order of fox and giraffe.
  // Apparently, giraffe would spill over into fox.
  // It will take extra characters that haven't been assigned
  // because "animal" is less than 8 characters

  // Since it doesn't have a \0, fox keeps reading characters
  // and moves into the neighboring array memory (giraffe)
 
}
