#include <stdio.h>
#include <stdlib.h>
void enqueue(int queues[], int n);
void dequeue(int queues[]);
void display();
int front=-1, rear=-1;
int main()
{
    int n;
    printf("Enter Queue size: ");
    scanf("%d", &n);
    int queues[n];
    enqueue(queues, n);
    display(queues);
    dequeue(queues);
    display(queues);
    return 0;
}
void enqueue(int queues[], int n)
{
    int num;
    for(int i=0; i<n; i++)
    {
        if(rear==n-1)
        {
            printf("Overflow\n");
            break;
        }
        else if(front == -1 && rear==-1)
        {
            front=0;
            rear=0;
            printf("Enter number: ");
            scanf("%d", &num);
            queues[rear]=num;
        }
        else
        {
            rear++;
            printf("Enter Number: ");
            scanf("%d", &num);
            queues[rear]=num;
        }
    }
}
void dequeue(int queues[])
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        printf("\n%d ", queues[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("\n%d\n", queues[front]);
        front++;
    }
}
void display(int queues[])
{
    if(front == -1 && rear==-1)
    {
        printf("\nQueues is empty.\n");
    }
    else
    {
        printf("\nThe Queues value is: \n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ", queues[i]);
        }
    }
}
