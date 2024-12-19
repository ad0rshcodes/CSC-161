#include "string_stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initialize an empty stack of strings
 *
 * \param s A pointer to a string_stack_t that should be initialized.
 */
void string_stack_init(string_stack_t *s)
{
  s->head = NULL;
}

/**
 * Destroy a stack that holds strings
 *
 * \param s A pointer to an initialized string_stack_t that should be destroyed.
 */
void string_stack_destroy(string_stack_t *s)
{
}

/**
 * Push a string to the top of the stack
 *
 * \param s   A pointer to an initialized string stack. The new value is added to the top of the
 *            stack. This function does NOT take ownership of s.
 * \param str A heap-allocated string that should be pushed onto the stack. This function takes
 *            ownership of str, and will free the underlying memory in string_stack_destroy.
 */
void string_stack_push(string_stack_t *s, char *str)
{
}

/**
 * Pop a string from the top of the stack and return it
 *
 * \param s A pointer to an initialized string stack. The string at the top of the stack will be
 *          removed and returned.
 * \returns an owning pointer to the string on the top of the stack, or NULL if the stack was empty.
 */
char *string_stack_pop(string_stack_t *s)
{
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
  return NULL;
}

/**
 * Get the string on the top of the stack, but do not remove it from the stack
 *
 * \param s A pointer to an initialized string stack. The string at the top of the stack will be
 *          returned, but the stack is not modified.
 * \returns a borrowed pointer to the string on the top of the stack, or NULL if the stack was empty.
 */
char *string_stack_peek(const string_stack_t *s)
{
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
  return NULL;
}
