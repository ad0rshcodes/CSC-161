#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    int a;
    a = 10;
    char b;
    b = 'v';
    bool c;
    c = true;

    float d = 103.543f;
    double e = 467.345678567;

    printf("%d \n", a);
    printf("%c \n", b);
    printf("%d \n", c);
    printf("%f \n", d);
    printf("%0.2lf \n", e);

    return 0;
}