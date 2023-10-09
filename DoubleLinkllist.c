#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head;

typedef struct node node;
void createnode(int n);
void display();

void insert_begin();
void insert_middle();
void insert_end();

void delete_begin();
void delete_middle();
void delete_end();

void createnode (int n)
{
    head=(node*)malloc(sizeof(node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next=NULL;
    head->prev=NULL;

    node *newnode, *temp;
    temp=head;
    for(int i=2; i<=n; i++)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=temp->next;
    }
}

void insert_begin()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data for newnode at first: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
}

void insert_middle()
{
    int n=3;
    node *newnode, *temp, *prev, *current;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data for newnode at middle: ");
    scanf("%d", &newnode->data);
    for(int i=1; i<n; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=newnode;
    newnode->prev=prev;
    newnode->next=current;
    current->prev=newnode;
}

void insert_end()
{
    node *newnode, *temp;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data for newnode at end: ");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void delete_begin()
{
    node *temp;
    temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    free(temp);
}

void delete_middle()
{
    int n=3;
    node *temp, *prev, *current;
    temp=head;
    for(int i=1; i<n; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    current->next->prev=prev;
    free(current);
}

void delete_end()
{
    node *temp, *prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void display()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->", temp-> data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    createnode(n);
    display();

    insert_begin();
    printf("\nAfter insert begin: \n");
    display();

    insert_middle();
    printf("\nAfter insert middle: \n");
    display();

    insert_end();
    printf("\nAfter insert end: \n");
    display();

    delete_begin();
    printf("\nAfter deleting first node: \n");
    display();

    delete_middle();
    printf("\nAfter deleting middle node: \n");
    display();

    delete_end();
    printf("\nAfter deleting end node: \n");
    display();

    return 0;
}
