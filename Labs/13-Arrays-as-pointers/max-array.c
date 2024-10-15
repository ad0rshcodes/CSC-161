#include <stdio.h>

#define LENGTH 10

// Original find_max using array indexing
double find_max(double array[], int array_size)
{
  double max = array[0];
  for (int j = 1; j < array_size; j++)
  {
    if (array[j] > max)
    {
      max = array[j];
    }
  }
  return max;
}

// Modified find_max using pointer arithmetic
double find_max_pointer(double *array, int array_size)
{
  double max = *array;
  double *ptr = array;
  for (int j = 1; j < array_size; j++)
  {
    ptr++;
    if (*ptr > max)
    {
      max = *ptr;
    }
  }
  return max;
}

// Function to find minimum using array indexing
double find_min(double array[], int array_size)
{
  double min = array[0];
  for (int j = 1; j < array_size; j++)
  {
    if (array[j] < min)
    {
      min = array[j];
    }
  }
  return min;
}

// Function to find average using pointer arithmetic
double find_average(double *array, int array_size)
{
  double sum = 0;
  double *ptr = array;
  for (int j = 0; j < array_size; j++)
  {
    sum += *ptr;
    ptr++;
  }
  return sum / array_size;
}

// Function to compute max, min, and average using pointers
void find_stats(double *array, int array_size, double *max, double *min, double *average)
{
  double sum = 0;
  double *ptr = array;
  *max = *min = *ptr;

  for (int j = 0; j < array_size; j++)
  {
    if (*ptr > *max)
      *max = *ptr;
    if (*ptr < *min)
      *min = *ptr;
    sum += *ptr;
    ptr++;
  }

  *average = sum / array_size;
}

int main()
{
  printf("Program to process real numbers.\n");

  double numbers[LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

  double bigNumber = find_max_pointer(numbers, LENGTH);
  printf("The maximum of ");
  for (int i = 0; i < LENGTH; i++)
  {
    printf(" %5.2lf", numbers[i]);
  }
  printf("\n");
  printf("is %5.2lf\n", bigNumber);

  double max, min, avg;
  find_stats(numbers, LENGTH, &max, &min, &avg);
  printf("Max: %5.2lf, Min: %5.2lf, Average: %5.2lf\n", max, min, avg);

  return 0;
}
