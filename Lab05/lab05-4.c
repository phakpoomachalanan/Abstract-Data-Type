#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    int shot;
    struct node *next;
}
node_t;

node_t *create(node_t *node, int id, int maxShot, int last);

int main(void) {
    int maxPlayer;
    int count;
    int maxShot;
    int c = 0;
    node_t *node  = (node_t *)malloc(sizeof(node_t));
    node_t *startNode = node;
    node_t *lastNode;
    
    scanf("%d %d", &maxPlayer, &count);
    
    for (int i=0; i<maxPlayer; i++)
    {
        scanf("%d", &maxShot);
        node = i == maxPlayer-1 ? create(node, i+1, maxShot+1, 1) : create(node, i+1, maxShot+1, 0);
    }
    node->next = startNode;

    for (;node->next != node;)
    {
        node = node->next;
        c = (c+1)%count;
        if (c == 0)
        {
            node->shot--;
        }
        if (node->shot == 0)
        {
            lastNode->next = node->next;
        }
        lastNode = node;
    }

    printf("%d\n", node->id);

    return 0;
}

node_t *create(node_t *node, int id, int maxShot, int last)
{
    node->id = id;
    node->shot = maxShot;
    node->next = last == 1 ? NULL : (node_t *)malloc(sizeof(node_t));
    
    return last == 1 ? node : node->next;
}
