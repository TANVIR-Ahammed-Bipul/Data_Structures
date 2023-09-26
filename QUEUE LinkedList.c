#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *front = NULL;
node *rear = NULL;

void enqueue(int n);
void dequeue();
void display();

int main()
{
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n");

    int choice;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int n)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("\nEnter a number to enqueue: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *temp = front;
        printf("Dequeued Element: %d\n", temp->data);

        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }

        free(temp);
    }
}

void display()
{
    node *temp = front;

    if (temp == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");
        while (temp != NULL)
        {
            printf("|%d|\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
