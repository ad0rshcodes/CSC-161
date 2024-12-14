#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"

/* Function to create a mazeSquare
 *
 * Input: c is a character, either *, _, or 7
 *        row is the row of this square in the larger maze
 *        col is the column of this square in the larger maze
 *
 * Output: returns a pointer to a mazeSquare type. Ownership is passed back.
 **/
mazeSquare_t *makeSquare(char c, int row, int col)
{
  mazeSquare_t *square = malloc(sizeof(mazeSquare_t));
  if (square == NULL)
  {
    printf("Memory allocation failed\n");
    return NULL;
  }

  // Initialize all fields
  square->row = row;
  square->col = col;
  square->visited = false;
  square->solutionPiece = false;

  // Set walls based on character
  switch (c)
  {
  case '7': // Top and right walls
    square->hasTopWall = true;
    square->hasRightWall = true;
    break;
  case '|': // Only right wall
    square->hasTopWall = false;
    square->hasRightWall = true;
    break;
  case '_': // Only top wall
    square->hasTopWall = true;
    square->hasRightWall = false;
    break;
  case '*': // No walls
    square->hasTopWall = false;
    square->hasRightWall = false;
    break;
  default:
    printf("Invalid maze character: %c\n", c);
    free(square);
    return NULL;
  }

  return square;
}

/* The following three functions are helper functions to move between
 * 1D arrays and 2D arrays.
 * Given (r,c), representing a row and column in a 2D array with
 * numrows rows, Index returns the corresponding index
 * in a 1D array
 *
 * Given an index d in a 1D array, the other two functions return the
 * corresponding row and column indices in a 2D array
 */
int Index(int r, int c, int numcols)
{
  return (r * (numcols)) + c;
}

int rowfromIndex(int d, int numrows)
{
  return d / numrows;
}

int colfromIndex(int d, int numrows)
{
  return d % numrows;
}

/* Function to load a maze from a file, save it to a new
 * instance of a maze, and return the maze
 *
 * Input: fp is a pointer to a file that contains maze data
 * Output: a pointer to a maze_t. Ownership is passed back.
 */
maze_t *loadMaze(FILE *fp)
{
  maze_t *M = malloc(sizeof(maze_t));
  if (NULL == M)
  {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  // Read dimensions
  if (fscanf(fp, "%d %d\n", &M->numrows, &M->numcols) != 2)
  {
    free(M);
    return NULL;
  }

  // Read start position
  if (fscanf(fp, "%d %d\n", &M->startrow, &M->startcol) != 2)
  {
    free(M);
    return NULL;
  }

  // Read end position
  if (fscanf(fp, "%d %d\n", &M->endrow, &M->endcol) != 2)
  {
    free(M);
    return NULL;
  }

  // Allocate grid - Important fix here
  M->grid = malloc(M->numrows * M->numcols * sizeof(mazeSquare_t *));
  if (NULL == M->grid)
  {
    printf("Memory allocation failed.\n");
    free(M);
    return NULL;
  }

  // Read maze structure - with bounds checking
  for (int i = 0; i < M->numrows; i++)
  {
    for (int j = 0; j < M->numcols; j++)
    {
      char c = fgetc(fp);
      if (c == EOF || (c != '*' && c != '_' && c != '7' && c != '|'))
      {
        // Invalid character or unexpected EOF
        printf("Invalid maze character or unexpected end of file\n");
        // Clean up allocated memory
        for (int k = 0; k < i * M->numcols + j; k++)
        {
          free(M->grid[k]);
        }
        free(M->grid);
        free(M);
        return NULL;
      }
      int idx = Index(i, j, M->numcols);
      M->grid[idx] = makeSquare(c, i, j);
      if (M->grid[idx] == NULL)
      {
        // Clean up if square creation failed
        for (int k = 0; k < i * M->numcols + j; k++)
        {
          free(M->grid[k]);
        }
        free(M->grid);
        free(M);
        return NULL;
      }
    }
    char newline = fgetc(fp); // consume newline
    if (i < M->numrows - 1 && newline != '\n')
    {
      printf("Expected newline character\n");
      // Clean up
      for (int k = 0; k < (i + 1) * M->numcols; k++)
      {
        free(M->grid[k]);
      }
      free(M->grid);
      free(M);
      return NULL;
    }
  }

  return M;
}