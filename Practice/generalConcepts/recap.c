#include <stdio.h>

int main()
{
    printf("My name is Adarsh \n");

    int a = 10;
    float b = 10.5643845784578f;
    char c = 'b';
    double d = 10.5643845784578;

    printf("int is %d, float is %.13f, char is %c and double is %.13lf \n", a, b, c, d);
    printf("size of float is %d and size of double is %d", sizeof(b), sizeof(d));
    return 0;
}