#include <stdio.h>
#include "print_util.h"

/* functions to print specific sequences of characters */
void TopWall()
{
  printf("+-----");
}
void TopNoWall()
{
  printf("+     ");
}
void Empty()
{
  // no right wall
  printf("      ");
}
void Sol()
{
  printf("  *   ");
}
void SolRight()
{
  printf("  *  |");
}
void SolLeft()
{
  printf("|  *   ");
}
void SolLeftRight()
{
  printf("|  *  |");
}
void LeftWall()
{
  printf("|      ");
}
void RightWall()
{
  printf("     |");
}
void printBottom(maze_t *mymaze)
{
  for (int c = 0; c < mymaze->numcols; c++)
  {
    printf("+");
    printf("-----");
  }
  printf("+\n");
}

/* function to print a single row of the maze */
void printRow(maze_t *mymaze, int r)
{
  for (int subr = 0; subr < 4; subr++)
  {
    for (int c = 0; c < mymaze->numcols; c++)
    {
      struct mazeSquare *current = mymaze->grid[Index(r, c, mymaze->numcols)];

      // special case for the top subrow, we need to print top walls
      if (subr == 0)
      {
        if (current->hasTopWall)
        {
          TopWall();
        }
        else
        {
          TopNoWall();
        }
        if (c == mymaze->numcols - 1)
        {
          printf("+");
        }
      }

      // otherwise, another special case is if we're in the middle subrow \
      // of a solution square
      else if (subr == 2 && current->solutionPiece)
      {
        if (c == 0 && current->hasRightWall)
        {
          SolLeftRight();
        }
        else if (c == 0)
        {
          SolLeft();
        }
        else if (current->hasRightWall)
        {
          SolRight();
        }
        else
        {
          Sol();
        }
      }

      // next case, has RightWall
      else if (current->hasRightWall)
      {
        if (c == 0)
        {
          printf("|");
          RightWall();
        }
        else
        {
          RightWall();
        }
      }

      // next case, c == 0
      else if (c == 0)
      {
        LeftWall();
      }

      // all remaining cases
      else
      {
        Empty();
      }
    }
    printf("\n");
  }
}

/* Print the maze, row by row */
void printSolution(maze_t *mymaze)
{
  for (int r = 0; r < mymaze->numrows; r++)
  {
    printRow(mymaze, r);
  }
  printBottom(mymaze);
}
