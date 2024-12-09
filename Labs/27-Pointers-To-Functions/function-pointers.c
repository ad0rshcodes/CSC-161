#include <stdio.h>

int sum(int (*f)(int), int start, int end){

  int sum = 0;
  
  for (int i = start; i <= end; i++){
    sum += f(i);
  }

  return sum;
}

int g1(int a){return a*a;}
int g2 (int a){return a-1;}

int main(){

  printf("sum: %d \n", sum(g1, 1, 3));
  printf("testing g2: %d \n", sum(g2, 1, 5));

  return 0;
}
