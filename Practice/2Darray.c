#include <stdio.h>

void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = 2;
    int cols = 3;
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    printMatrix(rows, cols, matrix); // Pass rows, cols, and the array itself
    return 0;
}
