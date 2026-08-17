/* write a C program to create a single link list by inserting nodes at the left side usinf functions, with call by value concept*/

# include <stdio.h>
# include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}sl;

sl* INSERT (sl*);
void disp(sl*);
void count(sl*);

int main()
{
    sl*l=NULL;
    int ch;
    do
    {
        printf("\n 1.Insert \n2.Display \n3.Count \n4.Exit");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            l=INSERT(l);
            break;
            case 2:
            disp(l);
            break;
            case 3:
            count(l);
            break;
            case 4:
            printf("Exiting");
            break;
            default:
            printf("Invalid choice");
        }
    }
    while(ch!=4);
     return 0;
}

sl*INSERT(sl*l)
{
    sl*p=NULL;
    int v;
    p= (sl*)malloc(sizeof(sl));
    if(p!=NULL)
    {
        printf("\nEnter data:");
        scanf("%d",&v);
        p->data=v;
        p->next=l;
        l=p;
    }
    return(l);
}

void count(sl*l)
{
    int c;
    sl*p=NULL;
    while (l!=NULL)
    {
        c++;
        l=l->next;
    }
    printf("%d",c);
    c=0;
    p=l;
}

void disp(sl*l)
{
    while(l!=NULL)
    {
        printf("%d",l->data);
        l=l->next;
    }
}