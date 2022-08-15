#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int    data;
    struct node *next;
}
node_t;

typedef node_t stack_t;

stack_t *pop(stack_t *node)
{
    return node == NULL ?  NULL : node->next;
}

stack_t *push(stack_t *node, int number)
{
    node_t *newNode = (stack_t *)malloc(sizeof(stack_t));
    
    newNode->data = number;
    newNode->next = node;

    return newNode;
}

void top(stack_t *node)
{
    node == NULL ? printf("Stack is empty.\n") : printf("%d\n", node->data);
}

void empty(stack_t *s)
{
    s == NULL ? printf("Stack is empty.\n") : printf("Stack is not empty.\n");
}

void size(stack_t *s)
{
    int count = 0;
    node_t *node = s;

    while (node != NULL)
    {
        count++;
        node = node->next;
    }
    printf("%d\n", count);
}

int main(void)
{
    stack_t *s = NULL;
    int     n, i, command, value;

    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &command);
        switch(command)
        {
            case 1:
                scanf("%d", &value);
                s = push(s, value);
                break;
            case 2:
                top(s);
                break;
            case 3:
                s = pop(s);
                break;
            case 4:
                empty(s);
                break;
            case 5:
                size(s);
                break;
        }
    }
    return 0;
}