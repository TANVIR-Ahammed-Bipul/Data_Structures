#include <stdio.h>
#include <stdlib.h>
void enqueue(int queues[], int n);
void dequeue(int queues[]);
void display();

int front=-1, rear=-1;
int main()
{
    int n, choices;
    printf("Enter Queue size: ");
    scanf("%d", &n);
    int queues[n];
    printf("\nQueue Operation: \n");
    printf("\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n");

    while(1)
    {
        printf("Enter choices: ");
        scanf("%d", &choices);

        switch(choices)
        {
        case 1:
            enqueue(queues, n);
            break;
        case 2:
            dequeue(queues);
            break;
        case 3:
            display(queues);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid number\n");
        }
    }

    return 0;
}

void enqueue(int queues[], int n)
{
    int num;
    if(rear==n-1)
    {
        printf("Overflow\n");
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

void dequeue(int queues[])
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        printf("\n%d  are Dequeued\n", queues[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("\n%d are Dequeued\n", queues[front]);
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
    printf("\n");
}
