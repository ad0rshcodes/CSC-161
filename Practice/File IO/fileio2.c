#include <stdio.h>

int main()
{
    FILE *FI = fopen("./text2.txt", "r");

    char buffer[5];

    while (fgets(buffer, 5, FI) != NULL)
    {

        printf("%s", buffer);
    }

    return 0;
}