
#include <stdio.h>
#define MAX 10

void CQEnqueue(int cq[], int *front, int *rear);
void CQDequeue(int cq[], int *front, int *rear);
void CQDisplay(int cq[], int front, int rear);
void CQpeek(int cq[], int front, int rear);

int main()
{
    int cq[MAX], choice, front = -1, rear = -1;
    do
    {
        printf("\n\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                CQEnqueue(cq, &front, &rear);
                break;
            case 2:
                CQDequeue(cq, &front, &rear);
                break;
            case 3:
                CQDisplay(cq, front, rear);
                break;
            case 4:
                CQpeek(cq, front, rear);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}

void CQEnqueue(int cq[], int *front, int *rear)
{
    if((*rear + 1) % MAX == *front)
    {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    int item;
    printf("Enter the item to enqueue: ");
    scanf("%d", &item);

    if(*front == -1)
        *front = 0;

    *rear = (*rear + 1) % MAX;
    cq[*rear] = item;
    printf("Enqueued: %d\n", item);
}

void CQDequeue(int cq[], int *front, int *rear)
{
    if(*front == -1)
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    int item = cq[*front];
    if(*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % MAX;
    }
    printf("Dequeued: %d\n", item);
}

void CQDisplay(int cq[], int front, int rear)
{
    if(front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while(1)
    {
        printf("%d ", cq[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void CQpeek(int cq[], int front, int rear)
{
    if(front == -1)
    {
        printf("Queue is empty! Cannot peek.\n");
        return;
    }
    printf("Front element: %d\n", cq[front]);
}

