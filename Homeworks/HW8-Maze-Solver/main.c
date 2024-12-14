// Name: Adarsh Sharma
// Resources Used: Course Book and Labs
// Date: Dec 13, 2024

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "maze.h"
#include "print_util.h"

// To check if any valid move exists.
// returns false if no move exists.
bool isValidMove(maze_t *maze, int row, int col, int next_row, int next_col)
{
  // First check bounds
  if (next_row < 0 || next_row >= maze->numrows ||
      next_col < 0 || next_col >= maze->numcols)
  {
    return false;
  }
  // pointers to current and next squares
  mazeSquare_t *current = maze->grid[Index(row, col, maze->numcols)];
  mazeSquare_t *next = maze->grid[Index(next_row, next_col, maze->numcols)];

  // False if we revisit squares that have already been explored
  if (next->visited)
  {
    return false;
  }

  // Moving up
  if (next_row < row)
  {
    return !current->hasTopWall; // Check CURRENT square's top wall
  }
  // Moving down
  else if (next_row > row)
  {
    return !next->hasTopWall; // Check NEXT square's top wall
  }
  // Moving right
  else if (next_col > col)
  {
    return !current->hasRightWall; // Check current square's right wall
  }
  // Moving left
  else if (next_col < col)
  {
    mazeSquare_t *left_square = maze->grid[Index(row, next_col, maze->numcols)];
    return !left_square->hasRightWall; // Check left square's right wall
  }

  return false;
}

bool solveMaze(maze_t *maze)
{
  square_stack_t stack;
  square_stack_init(&stack);

  // movement directions: up, right, down, left
  int dr[] = {-1, 0, 1, 0};
  int dc[] = {0, 1, 0, -1};

  // Get start square
  mazeSquare_t *start = maze->grid[Index(maze->startrow, maze->startcol, maze->numcols)];
  start->visited = true;
  start->solutionPiece = true;
  square_stack_push(&stack, start);

  // Continue until stack is empty or solution is found

  while (stack.size > 0)
  {
    mazeSquare_t *current = square_stack_peek(&stack);

    // Check if we reached the end
    if (current->row == maze->endrow && current->col == maze->endcol)
    {
      square_stack_destroy(&stack);
      return true;
    }

    // Try each direction
    bool moved = false;
    for (int i = 0; i < 4 && !moved; i++)
    {
      int next_row = current->row + dr[i];
      int next_col = current->col + dc[i];

      if (isValidMove(maze, current->row, current->col, next_row, next_col))
      {
        mazeSquare_t *next = maze->grid[Index(next_row, next_col, maze->numcols)];
        next->visited = true;
        next->solutionPiece = true;
        square_stack_push(&stack, next);
        moved = true;
      }
    }

    // If we couldn't move in any direction, backtrack
    if (!moved)
    {
      mazeSquare_t *square = square_stack_pop(&stack);
      if (square != start)
      {
        square->solutionPiece = false;
      }
    }
  }

  square_stack_destroy(&stack);
  return false;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: %s <maze_file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  // load maze structure
  maze_t *maze = loadMaze(fp);
  fclose(fp);

  if (maze == NULL)
  {
    printf("Error loading maze\n");
    return 1;
  }

  if (solveMaze(maze))
  {
    printf("Solution found!\n");
    printSolution(maze);
  }
  else
  {
    printf("No solution exists!\n");
    printSolution(maze);
  }

  // clean up
  for (int i = 0; i < maze->numrows * maze->numcols; i++)
  {
    if (maze->grid[i] != NULL)
    {
      free(maze->grid[i]);
      maze->grid[i] = NULL; // Set to NULL after freeing
    }
  }
  free(maze->grid);
  free(maze);

  return 0;
}