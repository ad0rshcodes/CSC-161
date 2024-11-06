#include <stdio.h>

int main()
{
    FILE *pF = fopen("/Users/adarshsharma/CS/college/CSC-161/Practice/File IO/text.txt", "r");

    printf("%p\n", pF);

    int ch = fgetc(pF);

    printf("%c", ch);

    ch = fgetc(pF);

    printf("%c \n", ch);

    fclose(pF);

    FILE *pF2 = fopen("./text.txt", "r");

    int fileStream = fgetc(pF2);

    while (fileStream != EOF)
    {
        printf("%c", fileStream);
        fileStream = fgetc(pF2);
    }

    fclose(pF2);

    return 0;
}