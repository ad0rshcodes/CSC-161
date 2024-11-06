#include <stdio.h>

struct player
{
    char name[12];
    int score;
};

int main()
{
    struct player adarsh = {"Adarsh", 56};
    struct player daksh;

    printf("%d", adarsh.score);

    daksh.name = "daksh";

    return 0;
}