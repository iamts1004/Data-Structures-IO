#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[50],addr[200];
    long int accno, phn, adhr;
    float bal;
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
        printf("\nBank Management System\n");
        printf("\n*Main Menu*\n");
        printf("\n1.Opening an account\n2.Deleting an account\n3.Displaying all bank accounts\n4.Exit\n");
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
    char name[50], addr[200];
    float bal;
    long int adhr, phn, accno;

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
        printf("\nEnter account number:\n");
        scanf("%ld",&accno);
        printf("\nEnter aadhar number:\n");
        scanf("%ld",&adhr);
        printf("\nEnter address:\n");
        scanf("%s",&addr);
        printf("\nEnter phone number:\n");
        scanf("%ld",&phn);
        printf("\nEnter balance:\n");
        scanf("%f",&bal);

        printf("\nAccount added successfully!\n");
        ptr -> accno = accno;
        ptr -> phn = phn;
        ptr -> adhr = phn;
        ptr -> bal = bal;
        strcpy(ptr -> addr, addr);
        strcpy(ptr -> name ,name);
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
        printf("\nAccount deleted successfully!\n");
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nNo bank records to show.\n");
    }
    else
    {   printf("\nAccount details:\n");
        while(ptr != NULL)
        {
            printf("\nAccount number:%ld\n", ptr -> accno);
            printf("Account holder's name:%s\n", ptr -> name);
            printf("Aadhar number:%ld\n", ptr -> adhr);
            printf("Phone number:%ld\n", ptr -> phn);
            printf("Address:%s\n", ptr -> addr);
            printf("Balance:%f\n", ptr -> bal);

            ptr = ptr -> next;
        }
    }
}
