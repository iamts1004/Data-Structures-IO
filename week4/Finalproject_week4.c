#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
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
void update(long int n);
void display();
void withdraw(long int n);
void deposit(long int n);
void main ()
{
    int c; long int n;
    while(1)
    {
        system("cls");
        printf("\nBank Management System\n");
        printf("\n*Main Menu*\n");
        printf("\n1. Open an account\n2. Delete an account\n3. Display all bank accounts\n4. Update account\n");
        printf("5. Withdraw Money\n6. Deposit Money\n7. Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: insert();
                    break;
            case 2: del(n);
                    break;
            case 3: display();
                    break;
            case 4: printf("\nEnter account number:\n");
                    scanf("%ld", &n);
                    update(n);
                    break;
            case 5: printf("\nEnter account number:\n");
                    scanf("%ld", &n);
                    withdraw(n);
                    break;
            case 6: printf("\nEnter account number:\n");
                    scanf("%ld", &n);
                    deposit(n);
                    break;
            case 7: exit(0);
                    break;
            default:
            printf("\nEnter valid choice.\n");
        }
        getch();
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
        printf("\nMemory Error!\n");
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
        scanf("%s", addr);
        getchar();
        printf("\nEnter phone number:\n");
        scanf("%ld",&phn);
        printf("\nEnter balance:\n");
        scanf("%f",&bal);

        printf("\nAccount added successfully!\n");
        ptr -> accno = accno;
        ptr -> phn = phn;
        ptr -> adhr = adhr;
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
        printf("\nNo records to delete!\n");
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

void update(long int n)
{
    struct node *ptr;
    ptr = front;
    char name[50], addr[200];
    float bal;
    long int adhr, phn, accno;

    if(front == NULL)
    {
        printf("\nNo bank records to update.\n");
        return;
    }
    else
    {   while(ptr -> accno != n)
            {ptr = ptr -> next;
             if(ptr == NULL)
              {
               printf("\nAccount not found!\n");
               return;
              }
             }

        if(ptr != NULL)
        {
        printf("\nAccount details:\n");
        printf("\nAccount number:%ld\n", ptr -> accno);
        printf("Account holder's name:%s\n", ptr -> name);
        printf("Aadhar number:%ld\n", ptr -> adhr);
        printf("Phone number:%ld\n", ptr -> phn);
        printf("Address:%s\n", ptr -> addr);
        printf("Balance:%f\n", ptr -> bal);

        printf("\n\nUpdate details:\n");
        printf("\nEnter name:\n");
        scanf("%s", name);
        printf("\nEnter aadhar number:\n");
        scanf("%ld",&adhr);
        printf("\nEnter address:\n");
        scanf("%s", addr);
        printf("\nEnter phone number:\n");
        scanf("%ld",&phn);

        printf("\nAccount updated successfully!\n");
        ptr -> phn = phn;
        ptr -> adhr = adhr;
        strcpy(ptr -> addr, addr);
        strcpy(ptr -> name ,name);
        }
    }
}

void withdraw(long int n)
{
    struct node *ptr;
    ptr = front;
    char name[50];
    float bal, a;
    long int accno;

    if(front == NULL)
    {
        printf("\nNo bank records.\n");
        return;
    }
    else
    {   while(ptr -> accno != n)
            {ptr = ptr -> next;
             if(ptr == NULL)
              {
               printf("\nAccount not found!\n");
               return;
              }
             }
        printf("\nHello, %s", ptr->name);
        printf("\nEnter amount to be withdrawn:\n");
        scanf("%f", &a);
        if(a>ptr->bal)
        {
            printf("\nInsufficient balance!\n");
            return;
        }
        else
        {
            ptr->bal = ptr->bal - a;
            printf("\nTransaction successful!\nBalance: %f\n", ptr->bal);
        }
    }
}

void deposit(long int n)
{
    struct node *ptr;
    ptr = front;
    char name[50];
    float bal, a;
    long int accno;

    if(front == NULL)
    {
        printf("\nNo bank records.\n");
        return;
    }
    else
    {   while(ptr -> accno != n)
            {ptr = ptr -> next;
             if(ptr == NULL)
              {
               printf("\nAccount not found!\n");
               return;
              }
             }
        printf("\nHello, %s", ptr->name);
        printf("\nEnter amount to be deposited:\n");
        scanf("%f", &a);
        ptr->bal = ptr->bal + a;
        printf("\nTransaction successful!\nBalance: %f\n", ptr->bal);
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
