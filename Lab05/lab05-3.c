#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int    data;
    struct node *next;
}
node_t;

node_t *append(node_t *node)
{
    node_t *startNode = node;
    char     data[8];

    getc(stdin);
    fgets(data, 8, stdin);
    
    if (node != NULL)
    {
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = (node_t *)malloc(sizeof(node_t));
        node = node->next;
        node->data = atoi(data);

        return startNode;
    }

    node = (node_t *)malloc(sizeof(node_t));
    node->data = atoi(data);
    node->next = NULL;

    return node;
}

void get(node_t *node)
{
    int  num;
    char data[8];

    getc(stdin);
    fgets(data, 8, stdin);
    num = atoi(data);

    for (int count=0; count<num; count++)
    {
        node = node->next;
    }
    printf("%d\n", node->data);
}

void show(node_t *node)
{
    for (; node != NULL;)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

node_t *reverse(node_t *startNode)
{
    node_t *next = NULL;
    node_t *back = NULL;
    node_t *node = startNode;

    if (startNode != NULL)
    {
        for (;node->next != NULL;)
        {
            next = node->next;
            node->next = back;
            back = node;
            node = next;
        }
        next = node->next;
        node->next = back;
        back = node;
        node = next;

        startNode = back;
    }

    return startNode;
}

node_t *cut(node_t *node)
{
    node_t *startNode;
    int start, stop;

    scanf("%d %d\n", &start, &stop);

    if (start != stop)
    {
        for (int i=0; i<stop; i++)
        {
            if (i == start)
            {
                startNode = node;
            }
            node = node->next;
        }
        node->next = NULL;
    }
    else 
    {
        for (int i=0; i<=stop; i++)
        {
            if (i == start)
            {
                startNode = node;
                break;
            }
            node = node->next;
        }
        node->next = NULL;
    }

    return startNode;
}

int main(void)
{
    node_t *startNode;
    int    n,i;
    char   command;
    
    startNode = NULL;
    scanf("%d\n", &n);
    for (i=0; i<n; i++)
    {
        scanf(" %c", &command);
        switch (command)
        {
            case 'A': 
                startNode = append(startNode);
                break;
            
            case 'G':
                get(startNode);
                break;
            
            case 'S':
                show(startNode);
                break;
            
            case 'R':
                startNode = reverse(startNode);
                break;
            
            case 'C':
                startNode = cut(startNode);
                break;
            
            default:
                break; 
        }
    } 
    return 0; 
} 