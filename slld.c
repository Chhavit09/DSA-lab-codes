/*
 Write a C program to create a single list by adding nodes to the right side (Dynamicaly)
 */

# include <stdio.h>
# include <stdlib.h>
typedef struct list {
    int data;
    struct list *next;
} sl;

int main()
{
    sl*p = NULL;
    sl*l=NULL;
    sl*r=NULL;
    int ch,v,c;
    while(1)
    {
        p=(sl*)malloc(sizeof(sl));
        if(p!=NULL)
        {
            printf("Enter the value: ");
            scanf("%d",&v);
            p->data=v;
            if (l==NULL && r==NULL)
            {
                l=p;
                r=p;
            }
            else
            {
                r->next=p;
                r=p;
            }
        }
        printf("\n Do you want to continue");
        scanf("%d",&ch);
        if(ch==0)
        {
            break;
        }
    }
    r->next=NULL;
    p=l;
    while (p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    p=l;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    printf("Total number of nodes are %d",c);
    return 0;
}