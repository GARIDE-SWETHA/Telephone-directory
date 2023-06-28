#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[20];
    char email[20];
    long int number;
    struct node *next;
};

struct node *head=NULL;

struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
}


void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->name);
        printf("%s\n",temp->email);
        printf("%ld\n",temp->number);  /* number is long int */
        temp=temp->next;
    }
}

void insert()
{
    struct node *temp,*newnode;
    newnode=getnode();
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    printf("Enter Name:\n");
    scanf("%s",newnode->name);
    printf("Enter email:\n");
    scanf("%s",newnode->email);
    printf("Enter number:\n");
    scanf("%ld",&newnode->number);
    temp->next=newnode;
    newnode->next=NULL;
    display(head);
}
struct node *create()
{
    struct node *temp,*newnode;
    if(head!=NULL)
        insert();
    else
    {
    newnode=getnode();
    head=newnode;
    temp=head;
    printf("Enter Name:\n");
    scanf("%s",newnode->name);
    printf("Enter email:\n");
    scanf("%s",newnode->email);
    printf("Enter number:\n");
    scanf("%ld",&newnode->number);
    newnode->next=NULL;
    display(head);
    }
}
void search()
{
    struct node *temp;
    char first[20]; /* space for input */
    temp=head;
    printf("Enter name to be searched:\n");
    scanf("%s",first);  /* you dont need '&' operator for string*/
   // scanf("%s",last);
    while((temp->name==first))
    {
        temp=temp->next;
    }
    printf("%s\n",temp->name);
    printf("%s\n",temp->email);
    printf("%ld\n",temp->number); /* number is long int */
}
struct node* Previous(struct node *c){
    struct node *t=head,*prev;
    while(t->next!=c){
        t=t->next;
    }
    prev=t;
    return prev;
}

void del()
{
    struct node *pretemp,*temp;
    char f[50];   /* you need a space to store input */
    temp=head;
    pretemp=head->next;
    printf("Enter name :");
    scanf("%s",f);   /* you dont need '&' operator to access a string */
    //scanf("%s",l);
    if(head==NULL){
        printf("NO data available");
        return;
    }
    else if(strcmp(head->name,f)==0){
        printf("\n%s\n%s\n%ld\n",temp->name,temp->email,temp->number);
        printf("This Data is Deleted Successfully");
        head=head->next;
    }
    else{
        while(temp!=NULL){
        if(strcmp(temp->name,f)==0){
            printf("\n%s\n%s\n%ld\n",temp->name,temp->email,temp->number);
            printf("This Data is Deleted Successfully");
            pretemp=Previous(temp);
            pretemp->next=temp->next;
            free(temp);
            break;
        }
        temp=temp->next;
     } /* missing curly bracket */
    }
    
}


int main()
{
    int op,ch;
    do{
        printf("-------Welcome--------\n");
        printf("1.Create\n2.Display\n3.Delete\n4.Search\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2: display(head);
            break;
            case 3: del();
            break;
            case 4:search();
            break;

        }
        printf("Do you want to continue ? \npress 1 for Yes \npress 0 for No: \n");
        scanf("%d",&op);
    }while(op);
return 0;
}