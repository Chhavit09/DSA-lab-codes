# include<stdio.h>
# include<string.h>
# define MAX 100
int SQEnq(int [], int);
int SQDeq(int [], int);
void SQDisplay(int [], int,int);
void SQPeek(int [], int,int);

int main()
{
    int queue[100],front=-1,rear=-1,ch,ele;
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&ele);
                rear=SQEnq(queue,ele);
                if(front==-1)
                {
                    front=0;
                }
                break;
            case 2:
                front=SQDeq(queue,front);
                if(front>rear)
                {
                    front=rear=-1; // Reset queue if empty
                }
                break;
            case 3:
                SQDisplay(queue,front,rear);
                break;
            case 4:
                SQPeek(queue,front,rear);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(ch!=5);
}
int SQEnq(int queue[], int ele)
{
    static int rear=-1;
    if(rear==MAX-1)
    {
        printf("Queue is full! Cannot enqueue %d.\n",ele);
        return rear;
    }
    else
    {
        rear++;
        queue[rear]=ele;
        return rear;
    }

}

int SQDeq(int queue[], int front)
{
    if(front==-1)
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return front;
    }
    else
    {
        printf("Dequeued: %d\n",queue[front]);
        front++;
        return front;
    }
}       

void SQDisplay(int queue[], int front, int rear)
{
    if(front==-1)
    {
        printf("Queue is empty! Nothing to display.\n");
    }
    else
    {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
 void SQPeek(int queue[], int front, int rear)
{
    if(front==-1)
    {
        printf("Queue is empty! Cannot peek.\n");
    }
    else
    {
        printf("Front element: %d\n",queue[front]);
    }

}

       