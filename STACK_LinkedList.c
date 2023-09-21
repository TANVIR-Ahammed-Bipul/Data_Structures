#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

int top = -1;
node *newnode = NULL;

void push(int n);
void pop();
void display();

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit\n");

    int choice;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(n);
            break;
        case 2:
            pop();
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

void push(int n)
{
    if (top == n - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("\nEnter a number to push: ");
        scanf("%d", &temp->data);
        temp->next = newnode;
        newnode = temp;
        top++;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        node *temp = newnode;
        printf("Popped Element: %d\n", temp->data);
        newnode = newnode->next;
        free(temp);
        temp--;
    }
}

void display()
{
    node *temp = newnode;
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements: \n");
        while (temp != NULL)
        {
            printf("|%d|\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
