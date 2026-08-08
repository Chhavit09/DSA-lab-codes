# include<stdio.h>
struct list
{
    int A;
    int B;
    struct list *next;
}x,y,z;
int main()
{
    struct list *p=NULL;
    x.A=6;
    x.B=7;
    y.A=8;
    y.B=9;
    z.A=10;
    z.B=11;
    p=&x;
    p->next=&y;
    p=p->next;
    p->next=&z;
    p=p->next;
    p->next=NULL;
    p=&x;
    while(p!=NULL)
    {
        printf("%d %d\n",p->A,p->B);
        p=p->next;
    }
}