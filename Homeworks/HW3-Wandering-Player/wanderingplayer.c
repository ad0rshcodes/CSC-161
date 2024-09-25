/**
 * Homework 3: Wandering Player
 * Author: Adarsh Sharma
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// #define numrowss 10
// #define numcolss 10

/* Function which prints the current state of the grid to the terminal
preconditions: numrows and numcols are integers, grid is a 2D array with numrows equal to the length of the first dimension of grid and numcols equal to the length of the second dimension of grid
postconditions: the exact contents of grid are printed to the terminal. No variables are changed
*/
void printgrid(int numrows, int numcols, char grid[numrows][numcols])
{
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
bool validmoveexists(int numrows, int numcols, char grid[numrows][numcols], int currentrow, int currentcol)
{
    char leftValue = grid[currentrow][currentcol - 1];
    char rightValue = grid[currentrow][currentcol + 1];
    char upperValue = grid[currentrow - 1][currentcol];
    char lowerValue = grid[currentrow + 1][currentcol];

    if (leftValue == '.' || rightValue == '.' || upperValue == '.' || lowerValue == '.')
    {
        return true;
    }

    return false;
}

int main()
{
    int numrows = 10;
    int numcols = 10;
    char field[10][10];

    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numcols; j++)
        {
            field[i][j] = '.';
        }
    }

    srand(time(NULL));

    int currentRow = rand() % numrows;
    int currentCol = rand() % numcols;

    char position = 'A';
    bool validMove = validmoveexists(numrows, numcols, field, currentRow, currentCol);

    do
    {
        field[currentRow][currentCol] = position;
        position++;
        printgrid(numrows, numcols, field);
        // printf("%c", position);

        while (field[currentRow][currentCol] == '.')
        {
            int direction = rand() % 4;

            if (direction == 0)
            {
            }
            else if (direction == 1)
        }

    } while (validMove && position >= 'Z');

    return 0;
}