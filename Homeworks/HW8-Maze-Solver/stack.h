#pragma once
#include <stdio.h>
#include "maze.h"

typedef struct maze_node
{
  mazeSquare_t *square;
  struct maze_node *next;
} maze_node_t;

typedef struct square_stack
{
  maze_node_t *top;
  int size;
} square_stack_t;

void square_stack_init(square_stack_t *s);
void square_stack_destroy(square_stack_t *s);
void square_stack_push(square_stack_t *s, mazeSquare_t *sqr);
void square_stack_print(square_stack_t *s);
mazeSquare_t *square_stack_pop(square_stack_t *s);
mazeSquare_t *square_stack_peek(const square_stack_t *s);
int square_stack_length(const square_stack_t *s);
