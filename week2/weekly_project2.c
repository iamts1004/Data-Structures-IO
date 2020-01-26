#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    char sname[50];
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void del();
void display();
void main ()
{
    int c;
    while(1)
    {
        printf("\n\t\t*Main Menu*\n");
        printf("Queue implementation for some management system:");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default:
            printf("\nEnter valid choice.\n");
        }
    }
}
void insert()
{
    struct node *ptr;
    int n; char name[50];

    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow!\n");
        return;
    }
    else
    {
        printf("\nEnter name:\n");
        scanf("%s", name);
        printf("\nEnter value:\n");
        scanf("%d",&n);

        printf("\nElement added successfully!\n");
        ptr -> data = n;
        strcpy(ptr -> sname ,name);
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else
        {
            rear -> next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void del ()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("\nUnderflow!\n");
        return;
    }
    else
    {
        ptr = front;
        front = front -> next;
        free(ptr);
        printf("\nElement deleted successfully!\n");
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nEmpty queue.\n");
    }
    else
    {   printf("\nQueue Data:\n");
        while(ptr != NULL)
        {
            printf("\n%s, %d\n", ptr -> sname, ptr -> data);

            ptr = ptr -> next;
        }
    }
}
