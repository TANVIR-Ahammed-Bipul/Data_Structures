#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;   //Just create Link List......
node *head;
void create_node(int n);
void display();

void insert_begin();        //Inserting newnode......
void insert_middle();
void insert_end();

void delete_begin();        //Deleting node......
void delete_middle();
void delete_end();

void search(int data);

void create_node(int n)
{
    head=(node*)malloc(sizeof(node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next=NULL;

    node *newnode, *temp;
    temp=head;
    for(int i=2; i<=n; i++)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}

void insert_begin()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter data for insert_begin: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
}

void insert_middle()
{
    int n=3;
    node *newnode, *temp, *prev, *current;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter data for insert_middle: ");
    scanf("%d", &newnode->data);
    for(int i=1; i<n; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=newnode;
    newnode->next=current;
}

void insert_end()
{
    node *newnode, *temp;
    temp = head;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data for insert_end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL; // Make sure the new node points to NULL

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}


void delete_begin()
{
    node *temp;
    temp=head;
    head=temp->next;
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
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void search(int data)
{
    node *temp;
    temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data found at node %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Data not found in the list.\n");
}


int main()
{
    int n;
    printf("Enter number of node you want: ");
    scanf("%d", &n);
    create_node(n);

    printf("\nThe inserted node are: \n");
    display();

    insert_begin();
    printf("\nAfter Insert newnode at begin: \n");
    display();

    insert_middle();
    printf("\nAfter Insert newnode at middle: \n");
    display();

    insert_end();
    printf("\nAfter Insert newnode at end: \n");
    display();

    delete_begin();
    printf("\nAfter Deleting node at first: \n");
    display();

    delete_middle();
    printf("\nAfter Deleting node at middle: \n");
    display();

    delete_end();
    printf("\nAfter Deleting node at end: \n");
    display();

    int data;
    printf("\nEnter data you want to search: ");
    scanf("%d", &data);
    search(data);

    return 0;
}
