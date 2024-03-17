#include <stdio.h>
#define size 50
int top = -1;
char exp[size];
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int overflow()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

void push(char x)
{
    if (overflow())
    {
        printf("\n overflow");
    }
    top++;
    exp[top] = x;
}

char pop()
{
    if (isempty())
    {
        printf("\n stack is empty");
    }
    char res;
    res = exp[top];
    top--;
    return res;
}
int paranthesis(char exp[],char x)
{

    int i=0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {

            if (isempty())
            {
                return 0;
            }
            x = pop();
            switch (exp[i])
            {
            case ')':
                if (x != '(')
                    return 0;
                break;
            case '}':
                if (x != '{')
                    return 0;
                break;
            case ']':
                if (x != '[')
                    return 0;
                break;

            default:
                return 0;
            }
        }
        i++;
    }
    return isempty();
}

int main()
{
    int x;
    printf("\n enter expression:");
    scanf("%s", exp);
    int r = paranthesis(exp,x);
    if (r)
    {
        printf("\n it balanced");
    }
    else
    {
        printf("\n it not balanced");
    }
    return 0;
}
