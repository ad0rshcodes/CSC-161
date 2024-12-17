/**
 * malloc, relloc, free
 */

#include <stdio.h>
#include <stdlib.h>

struct names
{
    char *name;
    int value;
};

typedef struct data
{
    int value;
    char *names;
} data_t;

void printsomething(struct names c)
{
    printf("\n %s: \n", c.name);
}

void printsomething2(data_t c)
{
    printf("%d", c.value);
}

void changesomething(int c[])
{
    c[0] = 578;
}

int main()
{
    int *intArr = malloc(5 * sizeof(int));
    intArr[0] = 34;
    intArr[1] = 42;
    intArr[3] = 68;

    printf("%d \n", intArr[0]);

    changesomething(intArr);

    printf("%d \n", intArr[0]);

    struct names school = {"Adarsh", 56};
    struct names tuition;

    tuition.name = "Daksh";
    tuition.value = 69;

    printf("%s \n", school.name);
    printf("%d \n", school.value);
    printf("%s \n", tuition.name);
    printf("%d \n", tuition.value);

    struct names arr[] = {school, tuition};

    data_t var1 = {22, "dfghjk"};
    data_t var2 = {28, "qerty"};

    printf("%s \n", var1.names);
    printf("%d \n", var1.value);

    // int *arr3 = malloc(sizeof(int) * 1);

    // arr3[0] = 52;

    // printf("%d \n", *arr3);

    // realloc(arr3, 2 * sizeof(arr3));

    // arr3[1] = 69;
    // printf("%d", *(arr3 + 1));

    printsomething2(var2);

    return 0;
}