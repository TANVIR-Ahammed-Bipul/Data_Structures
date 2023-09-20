#include <stdio.h>
#include <stdlib.h>
void push(int stack[], int n);
void pop(int stack[]);
void display(int stack[]);
int top=-1;
int main()
{
    int n;
    printf("Enter stack size: ");
    scanf("%d", &n);
    int stack[n];
    push(stack, n);
    display(stack);
    pop(stack);
    display(stack);
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
        printf("Enter number you want to push: \n");
        for(int i=1; i<=max_stack; i++)
        {
            scanf("%d", &num);
            top++;
            stack[top]=num;
        }
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
        printf("After popped %d\n", stack[top]);
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
        for(int i=0; i<=top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\nThe top value is: %d\n", stack[top]);
}
