#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double *stack;
    int top;
    int max;
}
Stack;

Stack create(Stack data, int maxLength);
void pop(Stack *data);
void push(Stack *data, double number);
void doSomething(Stack *data, char operator);

int main(void)
{
    char  c;
    int   maxLength = 0;
    Stack data;

    scanf("%d\n", &maxLength);
    data = create(data, maxLength);

    while ((c = getc(stdin)) != '\n')
    {
        if (c < '0' || c > '9')
        {
            doSomething(&data, c);
        }
        else
        {
            push(&data, atoi(&c));
        }
    }
    printf("%.2lf\n", data.stack[data.top]);
}

Stack create(Stack data, int maxLength)
{
    data.stack = (double *)malloc(sizeof(int) * maxLength);
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

void push(Stack *data, double number)
{
    if (data->top == data->max)
    {
        return;
    }

    data->stack[++data->top] = number;
}

void doSomething(Stack *data, char operator)
{
    double num1, num2;

    num2 = data->stack[data->top];
    pop(data);
    num1 = data->stack[data->top];
    pop(data);

    switch(operator)
    {
        case '+':
            push(data, num1 + num2);
            break;
        case '-':
            push(data, num1 - num2);
            break;
        case '*':
            push(data, num1 * num2);
            break;
        case '/':
            push(data, num1 / num2);
            break;
    }

}