# include<stdio.h>
# include<stdlib.h>
int main()
{
    int *p=NULL,n,i,s=0;
    float av=0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++)
    {
        s=s+p[i];
        free(p);
    }
    av=(float)s/n;
    printf("Sum: %d\n",s);
    printf("Average: %f\n",av);
    free(p);
}
