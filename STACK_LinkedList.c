#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *top=NULL;

void push(int n);
void pop();
void display();
void peek();

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Peek\n\t5. Exit\n");

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
            peek();
            break;
        case 5:
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
        node *newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("\nEnter a number to push: ");
        scanf("%d", &newnode->data);
        newnode->next = top;
        top = newnode;
    }
}

void pop()
{
    node *temp;
    temp=top;
    if (temp == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Popped Element: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    node *temp;
    temp=top;
    if (top == NULL)
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

void peek()
{
    if(top==NULL)
    {
        printf("\nTop is NULL.\n");
    }
    else
    {
        printf("\nPeek value is: %d\n", top->data);
    }
}
