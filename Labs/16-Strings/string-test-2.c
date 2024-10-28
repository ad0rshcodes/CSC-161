#include <stdio.h>
#include <string.h>

int main (){

  char computerscience[16] = "isawesome";
  char isawesome[16] = "computerscience";

  printf("strlen (computerscience): %lu\n", strlen (computerscience) ); // 9
  printf("strlen (isawesome): %lu\n", strlen (isawesome) ); // 15

  printf("computerscience: %s\n", computerscience ); //isawesome
  printf("isawesome: %s\n", isawesome ); //computerscience
  return 0;
    }
