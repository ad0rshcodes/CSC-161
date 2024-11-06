#include <stdio.h>

int main()
{
    float marks[5] = {0};

    printf("%p \n", &marks);
    printf("%p \n", marks);
    printf("%p \n", marks + 1);
    printf("%p \n", marks + 2);
    printf("%p \n", marks + 3);

    printf("%f \n", *(marks + 3));

    // for (int i = 0; i < sizeof(marks) / sizeof(marks[0]); i++)
    // {
    //     scanf("%f", &marks[i]);
    // }

    // for (int i = 0; i < sizeof(marks) / sizeof(marks[0]); i++)
    // {

    //     printf("%0.1f ", marks[i]);
    // }

    return 0;
}