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
  // The list has no nodes, so head points to NULL
  lst->head = NULL;
}

/**
 * Destroy a linked list that holds strings.
 *
 * \param lst A pointer to an initialized string_list_t that should be destroyed.
 */
void string_list_destroy(string_list_t *lst)
{
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
  string_node_t *newNode = malloc(sizeof(string_node_t));

  if (newNode == NULL)
  {
    exit(EXIT_FAILURE);
  }

  newNode->value = malloc(sizeof(str));
  strcpy(newNode->value, str);

  newNode->next = lst->head;
  lst->head = newNode;
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
  return 0;
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
  string_node_t *cursor = lst->head;
  string_node_t *temp;

  if (strcmp(cursor->value, str) == 0)
  {
    lst->head = cursor->next;
    free(cursor->value);
    free(cursor);
    return true;
  }

  while (cursor->next != NULL)
  {
    if (strcmp(cursor->next->value, str) == 0)
    {
      temp = cursor->next;
      cursor->next = cursor->next->next;
      free(temp->value);
      free(temp);
      return true;
    }

    cursor = cursor->next;
  }

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
  string_node_t *cursor = lst->head;
  int count = 0;
  while (cursor != NULL)
  {
    count++;
    cursor = cursor->next;
  }

  return count;
}

/**
 * Print the elements of a string list, one per line.
 *
 * \param lst A pointer to an initialized string list that should be printed.
 */
void string_list_print(const string_list_t *lst)
{
  string_node_t *cursor = lst->head;

  while (cursor != NULL)
  {
    printf("%s, ", cursor->value);
    cursor = cursor->next;
  }
}
