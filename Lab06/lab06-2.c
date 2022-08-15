#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int    data;
    struct node *next;
}
node_t;

typedef node_t queue_t;

queue_t *dequeue(queue_t *node)
{
    if (node == NULL)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    printf("%d\n", node->data);

    return node->next;
}

queue_t *enqueue(queue_t *node, int number)
{
    node_t *newNode = node;

    //printf("28: %p\n", newNode);

    if (node == NULL)
    {
        newNode = (queue_t *)malloc(sizeof(node_t));
        newNode->data = number;
        newNode->next = NULL;

        return newNode;
    }
    while (newNode->next != NULL)
    {
        newNode = newNode->next;
        //printf("33: %p\n", newNode);
    }

    newNode->next = (queue_t *)malloc(sizeof(node_t));
    //printf("37: %p\n", newNode);
    newNode = newNode->next;
    newNode->data = number;
    newNode->next = NULL;

    return node;
}

void show(queue_t *q)
{
    node_t *node = q;

    if (q == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void empty(queue_t *q)
{
    q == NULL ? printf("Queue is empty.\n") : printf("Queue is not empty.\n");
}

void size(queue_t *q)
{
    int count = 0;
    node_t *node = q;

    while (node != NULL)
    {
        count++;
        node = node->next;
    }
    printf("%d\n", count);
}

int main(void)
{
    queue_t *q = NULL;
    int     n, i, command, value;

    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &command);
        switch(command)
        {
            case 1:
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
        }
    }
    return 0;
}