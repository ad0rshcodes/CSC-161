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
  lst->length = 0;
}

/**
 * Destroy a linked list that holds strings.
 *
 * \param lst A pointer to an initialized string_list_t that should be destroyed.
 */
void string_list_destroy(string_list_t *lst)
{
  while (lst->head != NULL)
  {
    string_node_t *temp = lst->head->next;
    free(lst->head->value);
    free(lst->head);
    lst->head = temp;
  }

  lst->head = NULL;
  lst->length = 0; // Reset length to 0 after destroying the list
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
  newNode->value = str;
  newNode->next = NULL;

  if (lst->head == NULL || strcmp(str, lst->head->value) < 0)
  {
    newNode->next = lst->head;
    lst->head = newNode;
  }
  else
  {
    string_node_t *current = lst->head;
    while (current->next != NULL && strcmp(str, current->next->value) >= 0)
    {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }

  lst->length++; // Update the length after insertion
}

// Storing a list in sorted order makes functions like string_list_count and search operations more efficient, as we can potentially stop traversing early when elements are out of order.

/**
 * Count the number of times a value appears in the given list.
 *
 * \param lst A pointer to an initialized string list.
 * \param str Count the number of times a value matching this string appears in the list.
 * \returns the number of times str was found in lst
 */
size_t string_list_count(const string_list_t *lst, const char *str)
{
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
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
  if (lst->head == NULL)
    return false;

  if (strcmp(lst->head->value, str) == 0)
  {
    string_node_t *temp = lst->head;
    lst->head = lst->head->next;
    free(temp->value);
    free(temp);
    lst->length--; // Decrement length after removal
    return true;
  }

  string_node_t *current = lst->head;
  while (current->next != NULL)
  {
    if (strcmp(current->next->value, str) == 0)
    {
      string_node_t *temp = current->next;
      current->next = current->next->next;
      free(temp->value);
      free(temp);
      lst->length--; // Decrement length after removal
      return true;
    }
    current = current->next;
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
  return lst->length;
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
    printf("%s \n", cursor->value);
    cursor = cursor->next;
  }
}
