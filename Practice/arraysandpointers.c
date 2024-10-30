#include <stdio.h>

void arrayinput(char ptr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Enter %d character: ", i);
        scanf(" %c", ptr + i);
    }
}

void arrayoutput(char *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d element of the array is %c and its address in the stack is %p \n", i, *(ptr + i), ptr + i);
    }
}

int main()
{

    int len;
    printf("How many characters do you want to store: ");
    scanf("%d", &len);

    char alpha[len];

    arrayinput(alpha, len);
    arrayoutput(alpha, len);

    return 0;
}