#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int value;
    struct student *next;
} student;

void createNode(int value, student *head)
{
    student *newNode = malloc(sizeof(student));
    student *tempNode = head;
    head = newNode;
    newNode->next = tempNode;
    printf("node created \n");
    // printf("%p", head);
}

void printList(student *head)
{
    printf("Inside print");
    while (head != NULL)
    {
        printf("%d", head->value);
        head = head->next;
    }
}

int main(int argc, char *argv[])
{
    student *head = NULL;

    createNode(10, head);
    createNode(30, head);
    createNode(100, head);

    printList(head);

    return 0;
}
