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
void string_list_init(string_list_t *lst)
{
  lst->length = 0;
  lst->capacity = 10;
  lst->arr = malloc(lst->capacity * sizeof(char *));
}

/**
 * Destroy a linked list that holds strings.
 *
 * \param lst A pointer to an initialized string_list_t that should be destroyed.
 */
void string_list_destroy(string_list_t *lst)
{
  for (int i = 0; i < lst->length; i++)
  {
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
void string_list_insert(string_list_t *lst, char *str)
{
}

/**
 * Add a string to the end of a string list.
 *
 * \param lst A pointer to an initialized string list. The new value is added to the back of this
 *            list. This function does NOT take ownership of lst.
 * \param str A heap-allocated string that should be appended to the list. This function takes
 *            ownership of str, and will free the underlying memory in string_list_destroy.
 */
void string_list_append(string_list_t *lst, char *str)
{
  if (lst->length == lst->capacity)
  {
    lst->arr = realloc(lst->arr, sizeof(char *) * 2 * lst->capacity);
    lst->capacity = 2 * lst->capacity;
  }

  lst->arr[lst->length] = str;
  lst->length++;
}

/**
 * Count the number of times a value appears in the given list.
 *
 * \param lst A pointer to an initialized string list.
 * \param str Count the number of times a value matching this string appears in the list.
 * \returns the number of times str was found in lst
 */
size_t string_list_count(const string_list_t *lst, const char *str)
{
  size_t count = 0;
  for (int i = 0; i < lst->length; i++)
  {
    if (strcmp(str, lst->arr[i]) == 0)
    {
      count++;
    }
  }

  return count;
}

/**
 * Remove a string from the list.
 *
 * \param lst A pointer to an initialized string list. The first matching occurrence of str in this
 *            list will be removed.
 * \param str The first exact match of this string should be removed from the list.
 * \returns true if the value was found and removed, and false otherwise
 */
bool string_list_remove(string_list_t *lst, const char *str)
{
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
  return false;
}

/**
 * Calculate the length of a string list
 *
 * \param lst A pointer to an initialized string list.
 * \returns the length of the list
 */
size_t string_list_length(const string_list_t *lst)
{
  return lst->length;
}

/**
 * Print the elements of a string list, one per line.
 *
 * \param lst A pointer to an initialized string list that should be printed.
 */
void string_list_print(const string_list_t *lst)
{
  for (int i = 0; i < lst->length; i++)
  {
    printf("%s, ", lst->arr[i]);
  }
}
