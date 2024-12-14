#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct mazeSquare
{
  // Wall variables
  bool hasTopWall;
  bool hasRightWall;

  // Other variables
  bool visited;
  bool solutionPiece;

  // Location of this square in a larger maze.
  int row;
  int col;
} mazeSquare_t;

/* Define a maze structure */
typedef struct maze
{
  // dimensions of maze
  int numrows;
  int numcols;

  // grid coordinates for the starting maze square
  int startrow;
  int startcol;

  // grid coordinates for the final maze square
  int endrow;
  int endcol;

  // pointer to 2D array of maze squares
  mazeSquare_t **grid;
} maze_t;

mazeSquare_t *makeSquare(char, int, int);
int Index(int r, int c, int numcols);
int rowfromIndex(int, int);
int colfromIndex(int, int);
maze_t *loadMaze(FILE *);
