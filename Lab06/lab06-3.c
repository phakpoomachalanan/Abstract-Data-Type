#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *stack;
    int  top;
    int  max;
}
Stack;

Stack create(Stack data, int maxLength);
void pop(Stack *data);
void push(Stack *data, char bracket);
int check(Stack *data);

int main(void)
{
    char  c;
    int   maxLength = 0;
    int   times = 0;
    Stack data;

    scanf("%d\n", &maxLength);
    data = create(data, maxLength);

    if (maxLength%2 == 0)
    {
        while ((c = getc(stdin)) != '\n')
        {
            push(&data, c);
            if (c == ')' || c == ']' || c == '}')
            {
                times++;
                if (check(&data) != 1)
                {
                    printf("0\n");
                    return 0;
                }
            }
        }
        if (times != maxLength/2)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    else
    {
        printf("0\n");
    }

    return 0;

}

Stack create(Stack data, int maxLength)
{
    data.stack = (char *)malloc(sizeof(char) * maxLength);
    data.top = -1;
    data.max = maxLength;

    return data;
}

void pop(Stack *data)
{
    if (data->top == data->max)
    {
        return;
    }
    data->top--;
}

void push(Stack *data, char bracket)
{
    if (data->top == data->max)
    {
        return;
    }

    data->stack[++data->top] = bracket;
}

int check(Stack *data)
{
    char p1, p2;

    p1 = data->stack[data->top];
    pop(data);
    p2 = data->stack[data->top];
    pop(data);

    if (p1 == ')')
    {
        return p1 - p2;
    }

    return p1 - p2 - 1;
}