# include <stdio.h>
typedef struct 
{
    int A;
    int B;
    struct list *next;
} sl;
int main()
{
    sl x,y,z,*p=NULL;
    x.A=6;  
    x.B=7;
    y.A=8;
    y.B=9;
    z.A=10;
    z.B=11;
    x.next=&y;
    y.next=&z;
    z.next=NULL;
    p=&x;
    while(p!=NULL)
    {
        printf("%d %d\n",p->A,p->B);
        p=p->next;
    }
    return 0;

}