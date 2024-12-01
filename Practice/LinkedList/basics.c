#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[10];
    int marks;
    struct Student *next;
} Student;

void printLinkedList(Student *ptr)
{
    while (ptr != NULL)
    {
        printf("%s %d \n", ptr->name, ptr->marks);
        ptr = ptr->next;
    }
}

Student *createNode(char *str, int marks)
{
    Student *snt = malloc(sizeof(Student));
    strcpy(snt->name, str);
    snt->marks = marks;
    snt->next = NULL;

    return snt;
}

int main()
{
    Student *n1 = createNode("Adarsh", 56);
    Student *n2 = createNode("Rajesh", 65);
    Student *n3 = createNode("Daksh", 75);

    Student *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    printLinkedList(head);

    return 0;
}
