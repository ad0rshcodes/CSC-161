#include <stdio.h>

int subtractOne(int a){return a-1;}


void map(int length, int ptr[], int (*fn) (int)){
  for (int i = 0; i < length; i++){
    ptr[i] = fn(ptr[i]);
  }
}


int main(){

  int arr[] = {0,5,4,3,8};
  int length = sizeof(arr)/sizeof(arr[0]);
  map(length, arr, subtractOne);

  printf("%d \n", arr[2]);
  printf("%d \n", arr[3]);

  return 0;
}