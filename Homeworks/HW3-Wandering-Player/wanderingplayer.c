/**
 * Homework 3: Wandering Player
 * Author: Adarsh Sharma
 */

#include <stdio.h>
#include <stdbool.h>

/* Function which prints the current state of the grid to the terminal
preconditions: numrows and numcols are integers, grid is a 2D array with numrows equal to the length of the first dimension of grid and numcols equal to the length of the second dimension of grid
postconditions: the exact contents of grid are printed to the terminal. No variables are changed
*/
void printgrid(int numrows, int numcols, char grid[numrows][numcols])
{
    // for you to fill in
}

/* Function which checks whether there is currently a valid move from the current location
preconditions: numrows and numcols are integers, grid is a 2D array with numrows equal to the length of the first dimension of grid and numcols equal to the length of the second dimension of grid
currentrow is an integer between 0 and numrows-1.
currentcol is an integer between 0 and numcols-1.
postconditions: returns true if at least one of the directions of movement {left, right, up, down}  on the grid is valid, meaning that at least one direction does not move off the grid and contains a '.' character.
*/
bool validmoveexists(int numrows, int numcols, char grid[numrows][numcols], int currentrow, int currentcol)
{
    // for you to fill in
}