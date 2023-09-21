#include <stdio.h>
#include <stdlib.h>
void push(int stack[], int n);
void pop(int stack[]);
void display(int stack[]);

int top=-1;
int main()
{
    int n, choices;
    printf("Enter stack size: ");
    scanf("%d", &n);
    int stack[n];
    while(1)
    {
        printf("STACK Operation: \n");
        printf("\t1. PUSH Operation\n\t2. POP Operation\n\t3. Display Operation\n\t4. Exit\n");
        printf("Enter your choices: ");
        scanf("%d", &choices);
        switch (choices)
        {
        case 1:
            push(stack, n);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter valid Number.\n");
        }
    }
    return 0;
}

void push(int stack[], int n)
{
    int max_stack=n, num;
    if(top==max_stack-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("\nEnter number for push: ");
        scanf("%d", &num);
        top++;
        stack[top]=num;
    }
}

void pop(int stack[])
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("\nAfter popped %d\n", stack[top]);
        top--;
    }
}

void display(int stack[])
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The stack is: \n");
        for(int i=top; i>=0; i--)
        {
            printf("| %d |\n", stack[i]);
        }
    }
}
