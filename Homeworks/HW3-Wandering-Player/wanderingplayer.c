/**
 * Homework 3: Wandering Player
 * Author: Adarsh Sharma
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Length and Breadth of the grid
#define SIZE 10

/* Function which prints the current state of the grid to the terminal
preconditions: numrows and numcols are integers, grid is a 2D array with numrows equal to the length of the first dimension of grid and numcols equal to the length of the second dimension of grid
postconditions: the exact contents of grid are printed to the terminal. No variables are changed
*/

void printgrid(int numrows, int numcols, char grid[numrows][numcols])
{
    // Loop to traverse through rows first and then columns to print each element.
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numcols; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

/* Function which checks whether there is currently a valid move from the current location
preconditions: numrows and numcols are integers, grid is a 2D array with numrows equal to the length of the first dimension of grid and numcols equal to the length of the second dimension of grid
currentrow is an integer between 0 and numrows-1.
currentcol is an integer between 0 and numcols-1.
postconditions: returns true if at least one of the directions of movement {left, right, up, down}  on the grid is valid, meaning that at least one direction does not move off the grid and contains a '.' character.
*/

bool validmoveexists(int numrows, int numcols, char grid[numrows][numcols], int row, int col)
{
    // Conditions to check whether adjacent position is available.

    if (row > 0 && grid[row - 1][col] == '.') // Upper position
    {
        return true;
    }
    else if (row < numrows - 1 && grid[row + 1][col] == '.') // Below Position
    {
        return true;
    }
    else if (col > 0 && grid[row][col - 1] == '.') // Left Position
    {
        return true;
    }
    else if (col < numcols - 1 && grid[row][col + 1] == '.') // Right Position
    {
        return true;
    }
    return false;
}

int main()
{
    char grid[SIZE][SIZE]; // initialising 2d array
    int row;
    int col;
    char letter = 'A';

    srand(time(NULL));

    // Initialize grid with initial character: '.'
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = '.';
        }
    }

    // Choosing a starting position
    row = rand() % SIZE;
    col = rand() % SIZE;
    grid[row][col] = letter++;

    // While loop that runs until we reach 'Z' or no valid move exists.

    while (letter <= 'Z' && validmoveexists(SIZE, SIZE, grid, row, col))
    {
        int new_row = row;
        int new_col = col;
        bool moved = false;

        // While loop to run everytime moved = false.
        while (!moved)
        {
            int direction = rand() % 4; // 0: upwards, 1: downwards, 2: left, 3: right

            // Conditions to check that we are inside the grid and the adjacent spaces are '.'

            if (direction == 0 && row > 0 && grid[row - 1][col] == '.') // Moving Upwards
            {
                new_row = row - 1;
            }
            else if (direction == 1 && row < SIZE - 1 && grid[row + 1][col] == '.') // Moving Downwards
            {
                new_row = row + 1;
            }
            else if (direction == 2 && col > 0 && grid[row][col - 1] == '.') // Moving Left
            {
                new_col = col - 1;
            }
            else if (direction == 3 && col < SIZE - 1 && grid[row][col + 1] == '.') // Moving Right
            {
                new_col = col + 1;
            }

            if (new_row != row || new_col != col)
            {
                grid[new_row][new_col] = letter++;
                row = new_row;
                col = new_col;
                moved = true;
            }
        }

        printgrid(SIZE, SIZE, grid); // printing the current grid.
        printf("\n");
    }

    return 0;
}