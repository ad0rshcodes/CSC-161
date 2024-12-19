#include "string_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initialize an empty linked list that holds strings.
 * 
 * \param lst A pointer to a string_list_t that should be initialized.
 */
void string_list_init(string_list_t* lst) {
  lst->capacity = 5;
  lst->arr = (char**)malloc(sizeof(char*) * lst->capacity);
  lst->length = 0;
}

/**
 * Destroy a linked list that holds strings.
 * 
 * \param lst A pointer to an initialized string_list_t that should be destroyed.
 */
void string_list_destroy(string_list_t* lst) {

  for (int i = 0; i < lst->length; i++){
    free(lst->arr[i]);
  }
  free(lst->arr);
   
}

/**
 * Add a string to the front of a string list.
 * 
 * \param lst A pointer to an initialized string list. The new value is added to the front of this
 *            list. This function does NOT take ownership of lst.
 * \param str A heap-allocated string that should be inserted into the list. This function takes 
 *            ownership of str, and will free the underlying memory in string_list_destroy.
 */
void string_list_insert(string_list_t* lst, char* str) {
  
  if (lst->capacity <= lst->length){
    lst->arr = realloc(lst->arr, sizeof(char*)*(lst->capacity*2));
    lst->capacity = lst->capacity * 2;
  }
 
  // shifting all elements by 1.

  for (int i = lst->length - 1; i >=  0; i--){
    lst->arr[i+1] = lst->arr[i];
  //   memmove(lst->arr[1], lst->arr[0], sizeof(lst->arr));
    }
  lst->arr[0] = str;
  lst->length++;
  
}

/**
 * Add a string to the end of a string list.
 * 
 * \param lst A pointer to an initialized string list. The new value is added to the back of this
 *            list. This function does NOT take ownership of lst.
 * \param str A heap-allocated string that should be appended to the list. This function takes 
 *            ownership of str, and will free the underlying memory in string_list_destroy.
 */

/**
   Steps:
   1. Check capacity and length of the array. If they are equal, then realloc it by size one.
   2. After making sure we have memory, add the new element to the index length.  
 */
void string_list_append(string_list_t* lst, char* str) {

  if (lst->capacity <= lst->length){
    lst->arr = realloc(lst->arr, sizeof(char*)*(lst->capacity*2));
  }

  lst->arr[lst->length] = malloc(sizeof(str));
  strcpy(lst->arr[lst->length], str);
  lst->length++;
  //printf("Success");
  //printf("%s\n", lst->arr[lst->length]);
}

/**
 * Count the number of times a value appears in the given list.
 * 
 * \param lst A pointer to an initialized string list.
 * \param str Count the number of times a value matching this string appears in the list.
 * \returns the number of times str was found in lst
 */
size_t string_list_count(const string_list_t* lst, const char* str) {
  int counter = 0;
  
  for(int i = 0; i < lst->length; i++)
    {
      if(strcmp(str, lst->arr[i]) == 0)
        {
          counter++;
        }
    }
  return counter;
}

/**
 * Remove a string from the list.
 * 
 * \param lst A pointer to an initialized string list. The first matching occurrence of str in this 
 *            list will be removed.
 * \param str The first exact match of this string should be removed from the list.
 * \returns true if the value was found and removed, and false otherwise
 */
bool string_list_remove(string_list_t* lst, const char* str) {
  int index = 0;
  //runs through the array and finds the element to remove
  for(int i = 0; i < lst->length; i++)
    {
      //compares each element in the array to the element to be removed
      if(strcmp(str, lst->arr[i]) == 0)
        {
          //removes the element targeted and moves each element after back one element.
             
           for(int j = i; j < lst->length - 1; j++)
                  {
                  lst->arr[j] = lst->arr[j+1];
          //  memmove(lst->arr[i],lst->arr[i+1], sizeof(lst->arr));
               }
          
          lst->length--;
          return true;
        }
        
    }
  return false;
}

/**
 * Calculate the length of a string list
 * 
 * \param lst A pointer to an initialized string list.
 * \returns the length of the list
 */
size_t string_list_length(const string_list_t* lst) {
  return lst->length;
}

/**
 * Print the elements of a string list, one per line.
 * 
 * \param lst A pointer to an initialized string list that should be printed.
 */
void string_list_print(const string_list_t* lst) {
  int counter = 0;
  while(counter < lst->length)
    {
      printf("%s, ", lst->arr[counter]);
      counter++;
    }
  printf("\n");
}
