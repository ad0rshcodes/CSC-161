#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getDimension(FILE *fp, int *side)
{
    int c;
    while ((c = fgetc(fp)) != ' ' && c != '\n')
    {
        *side = (*side * 10) + (c - '0');
    }
}

void createGrid(int length, int bredth, char arr[length][bredth], FILE *fp)
{

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < bredth; j++)
        {
            int temp = fgetc(fp);
            if (temp == ' ')
            {
                temp = fgetc(fp);
                arr[i][j] = temp;
            }
            else
            {
                arr[i][j] = temp;
            }
        }
        fgetc(fp);
    }
}

int main()
{
    FILE *fp = fopen("puzzle1.txt", "r");
    int c;
    int length = 0;
    int bredth = 0;
    getDimension(fp, &length);
    getDimension(fp, &bredth);

    char grid[length][bredth];
    createGrid(length, bredth, grid, fp);

    printf("%d \n", length);
    printf("%d \n", bredth);

    fclose(fp);
    return 0;
}