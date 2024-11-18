#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int* arr = (int*) (malloc (sizeof(int)*8));
    if (arr == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
  for (int i=0; i<8; i++) {
    arr[i] = i;
  }


  int* arr2 = (int*) (calloc (8, sizeof(int)));
    if (arr2 == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
  for (int i=0; i<8; i++) {
    arr2[i] = i;
  }


  char* str = (char*) (malloc (14));
    if (str == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
  strcpy(str, "Hello");
  strcat(str, ", world.");
  printf("%s\n", str);

  char* str2 = (char*) (calloc(14, 1));
    if (str2 == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
  strcpy(str2, "Hello");
  strcat(str2, ", world");
  printf("%s\n", str2);


  return 0;
}
