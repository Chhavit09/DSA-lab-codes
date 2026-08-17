/* write a C program to create a single link list by inserting nodes at the right side using functions, with call by value concept*/

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
        printf("\nEnter your choice: ");
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
    sl*temp=NULL;
    int v;
    p= (sl*)malloc(sizeof(sl));
    if(p!=NULL)
    {
        printf("\nEnter data: ");
        scanf("%d",&v);
        p->data=v;
        p->next=NULL;
       if(l==NULL)
       {
        l=p;
       }
       else
       {
        temp=l;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
       }
    }
    return(l);
}

void count(sl*l)
{
    int c=0;
    if (l==NULL)
    {
        printf("List is empty");
    }
    else
    {
      while (l!=NULL)
        {
          c++;
          l=l->next;
        }
      printf("\nTotal nodes: %d",c);
    }
}

void disp(sl*l)
{
    if (l==NULL)
    {
        printf("List is empty");
    }
    else
    {
     printf("\nList: ");
     while(l!=NULL)
        {
          printf("%d -> ",l->data);
          l=l->next;
        }
      printf("NULL");
    }
}