#include<stdio.h>
#define max_stk 5

int top=-1;
int stack[max_stk];
void push()
{
    int x;
    if(top==max_stk-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter a value: ");
        scanf("%d", &x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }

    else
    {
        printf("Pooped element : %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Stack elements: \n");
        for(int i=top; i>=0; i--)
        {
            printf("|%d|\n", stack[i]);
        }
    }
}

int main()
{
    /*int n;
    printf("\nEnter the size of stk: ");
    scanf("%d", &n);*/
    printf("\nStack operation using array......\n");
    printf("\n\t 1.push\n\t2.pop\n\t3.display\n\t4.Exit\n");
    int choice=0;

    while(choice != 4)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        if(choice==1)
        {
            push();
        }
        else if(choice==2)
        {
            pop();
        }
        else if(choice==3)
        {
            display();
        }
        else if(choice == 4)
        {
            printf("\n\tExit");
        }
        else
        {
            printf("\nplease enter valid choice(1/2/3/4): ");
        }
    }
    return 0;
}
