# include<stdio.h>
# include <string.h>
# define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c; 
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %c\n", stack[top]);
}

int presedence(char c)
{
   switch(c)
   {
       case '^':
           return 3;
       case '*':
       case '/':
           return 2;
       case '+':
       case '-':
           return 1;
       default:
              return 0;
       
   }
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j=0;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    for(i=0; i<strlen(infix); i++)
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top];
                pop();
            }
            pop(); // pop the '('
        }
        else
        {
            while(top != -1 && presedence(stack[top]) >= presedence(infix[i]))
            {
                postfix[j++] = stack[top];
                pop();
            }
            push(infix[i]);
        }
    }
    while(top != -1)
    {
        postfix[j++] = stack[top];
        pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}