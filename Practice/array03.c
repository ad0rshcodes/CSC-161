#include <stdio.h>

int main()
{

    int tableCount;
    printf("How many tables: ");
    scanf(" %d", &tableCount);

    int tables[tableCount][10];
    int tableValues[tableCount];

    printf("whose tables do you want? \n Enter numbers: ");

    for (int i = 0; i < tableCount; i++)
    {
        scanf(" %d", tableValues + i);
    }

    for (int i = 0; i < tableCount; i++)
    {
        printf("%d table: ", *(tableValues + i));
        for (int j = 0; j < 10; j++)
        {
            tables[i][j] = *(tableValues + i) * (j + 1);
            printf("%d ", tables[i][j]);
        }
        printf("\n");
    }

    return 0;
}