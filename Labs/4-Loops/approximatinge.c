# include <stdio.h>
// Authors: Adarsh Sharma & Michael Getsos 09/09/24

int main (){

  // Request and Receive User input for n (number of terms)
  printf("Please enter a number:");
  int n; 
  scanf("%d", &n);

  float sum = 1; 

  for (int i = 1; i <= n; i ++){

    float product= 1; 
    
    for (int j = 1; j <= i; j++){
      product = product * j; // perform the factorial operation
    }

    sum += 1/product; // perform the summation
  }
  //Print result
  printf ("Approximation for e = %f", sum);
  return 0;
}

int question2 (){

  printf 
  
  return 0;
}
