#include <stdio.h>

int main(){
  int* p;
  int* q = (int*)malloc(sizeof(int));
  int* temp = q;
  if (q == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  int x = 5;
  p = &x;
  *q = 100;
  *p = 200;
  p = (int*)malloc(sizeof(int));
  if (p == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  q = &x;

  return 0;
}
