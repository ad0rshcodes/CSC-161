#include <stdio.h>

void reverse(char *ptr, int len)
{
    char temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + len - 1 - i);
        *(ptr + len - 1 - i) = temp;
    }
}

int main()
{

    char alpha[5] = {'a', 'b', 'c', 'd', 'e'};

    reverse(alpha, sizeof(alpha) / sizeof(alpha[0]));

    for (int i = 0; i < sizeof(alpha) / sizeof(alpha[0]); i++)
    {
        printf("%c \n", alpha[i]);
    }
    return 0;
}