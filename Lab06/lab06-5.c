#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char   letter;
    struct node *back;
}
node_t;

int main(void)
{
    node_t *node = NULL;
    node_t *lastNode = NULL;
    char   c;

    while ((c = getc(stdin)) != 'x')
    {
        node = (node_t *)malloc(sizeof(node_t));
        node->letter = c;
        node->back = lastNode;
        lastNode = node;
    }
    while ((c = getc(stdin)) != 'y')
    {
        if (node == NULL || node->letter != c)
        {
            printf("0\n");
            return 0;
        }
        node = node->back;
    }

    node != NULL ? printf("0\n") : printf("1\n");

    return 0;
}