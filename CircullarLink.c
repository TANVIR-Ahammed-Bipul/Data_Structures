#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *first;
    int data;
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


int main()
{
    int n;
    printf("Enter number of node size: ");
    scanf("%d", &n);
    createnode(n);
    display();
    printf("\nAfter inserting first....\n");
    insert_begin();
    display();
    printf("\nAfter inserting middle,,,,\n");
    insert_middle();
    display();
    printf("\nAfter inserting end....\n");
    insert_end();
    display();
    printf("\nAfter deleting first node: \n");
    delete_begin();
    display();
    printf("\nAfter deleting middle: \n");
    delete_middle();
    display();
    printf("\nAfter deleting end: \n");
    delete_end();
    display();

    return 0;
}

void createnode(int n)
{
    head=(node*)malloc(sizeof(node));
    printf("Enter data for node 1: ");
    scanf("%d", &head-> data);
    head->first=head;
    head->next=head;
    node *newnode, *temp;
    temp=head;
    for(int i=2; i<=n; i++)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode-> data);
        temp->next=newnode;
        newnode->first=temp;
        newnode->next=head;
        head->first=newnode;
        temp=temp->next;
    }
}

void insert_begin()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data for newnode at begin: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    newnode->first = head->first;
    head->first->next=newnode;
    head->first=newnode;
    head=newnode;
}
void insert_middle()
{
    int pos=2;
    node *newnode, *temp, *prev, *current;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("Insert data at middle: ");
    scanf("%d", &newnode-> data);
    for(int i=1; i<pos; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=newnode;
    newnode->first=prev;
    newnode->next=current;
    current->first=newnode;
}

void insert_end()
{
    node *temp, *newnode;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data for newnode: ");
    scanf("%d", &newnode->data);
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->first=temp;
    newnode->next=head;
    head->first=newnode;
}

void delete_begin()
{
    node *temp;
    temp=head;
    head->next->first=head->first;
    head->first->next=head->next;
    head=temp->next;
    free(temp);
}

void delete_middle()
{
    int pos=3;
    node *prev, *current, *temp;
    temp=head;
    for(int i=1; i<pos; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    current->next->first=current->first;
    free(current);
}

void delete_end()
{
    node *temp;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->first->next=temp->next;
    temp->next->first=temp->first;
}

void display()
{
    node* temp;
    temp = head;
    do
    {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("\n");
}
