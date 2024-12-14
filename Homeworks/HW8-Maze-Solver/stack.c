#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

/**
 * Initialize an empty stack of squares
 * param s A pointer to a square_stack_t that we should
 * initialize here.
 */
void square_stack_init(square_stack_t *s)
{
  s->top = NULL;
  s->size = 0;
}

/**
 * Destroy a stack that holds squares
 * param s A pointer to an initialized square_stack_t that should be destroyed.
 */
void square_stack_destroy(square_stack_t *s)
{
  while (s->top != NULL)
  {
    maze_node_t *temp = s->top;
    s->top = s->top->next;
    free(temp); // Only free the node
  }
  s->size = 0;
}

/**
 * Push a square to the top of the stack
 * param s   A pointer to an initialized square stack. The new value is added to the
 * top of the stack. This function does NOT take ownership of s.
 *
 * param str A heap-allocated mazeSquare that should be pushed onto the stack. This
 * function takes ownership of sqr, and will free the underlying memory in
 * square_stack_destroy.
 */
void square_stack_push(square_stack_t *s, mazeSquare_t *sqr)
{
  maze_node_t *new_node = malloc(sizeof(maze_node_t));
  if (new_node == NULL)
  {
    printf("Memory allocation failed\n");
    return;
  }
  new_node->square = sqr;
  new_node->next = s->top;
  s->top = new_node;
  s->size++;
}

/**
 * Pop a square from the top of the stack and return it
 * param s A pointer to an initialized square stack. The string at the top of the
 * stack will be removed and returned.
 * Returns an owning pointer to the square on the top of the stack, or NULL
 * if the stack was empty.
 */
mazeSquare_t *square_stack_pop(square_stack_t *s)
{
  if (s->top == NULL)
  {
    return NULL;
  }

  maze_node_t *temp = s->top;
  mazeSquare_t *sqr = temp->square;
  s->top = s->top->next;
  free(temp);
  s->size--;
  return sqr;
}

/**
 * Get the square on the top of the stack, but do not remove it from the stack
 * param s A pointer to an initialized square stack. The square at
 * the top of the stack will be  returned, but the stack is not modified.
 * returns a borrowed pointer to the square on the top of the stack, or NULL if the stack was empty.
 */
mazeSquare_t *square_stack_peek(const square_stack_t *s)
{
  if (s->top == NULL)
  {
    return NULL;
  }
  return s->top->square;
}
