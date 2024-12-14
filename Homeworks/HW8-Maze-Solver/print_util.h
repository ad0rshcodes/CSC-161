#include <stdio.h>
#include "maze.h"

void TopWall();
void TopNoWall();
void Empty();
void Sol();
void SolRight();
void SolLeft();
void SolLeftRight();
void LeftWall();
void RightWall();
void printBottom(maze_t* );
void printRow(maze_t* ,int r);
void printSolution(maze_t *);
