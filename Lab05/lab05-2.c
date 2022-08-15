#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *back;
    int number;
}
node_t;

typedef node_t list_t;

int count = 0;

list_t *create(list_t *node)
{
    char   ch;
    int    c = 0;
    node_t *lastNode = NULL;

    while ((ch = getc(stdin)) != '\n')
    {
        node->back = lastNode;
        node->number = ch - '0';
        lastNode = node;
        node = (node_t *)malloc(sizeof(node_t));
        c++;
    }
    count = c > count ? c: count;
    return lastNode;
}

void plus(list_t *node1, list_t *node2)
{
    char   *ans = (char *)malloc(sizeof(char) * count);
    int    num1, num2;
    int    sum = 0;
    int    c = count;
    node_t *lastNode = NULL;
    list_t *node;
    
    do
    {
        num1 = node1 != NULL ? node1->number : 0;
        num2 = node2 != NULL ? node2->number : 0;
        node1 = node1 != NULL ? node1->back : NULL;
        node2 = node2 != NULL ? node2->back : NULL;

        sum += num1 + num2;
        ans[c-1] = sum%10 +'0';
        sum /= 10;

        c--;
    }
    while (node1 != NULL || node2 != NULL);
    
    if (sum != 0)
    {
        printf("%d", sum);
    }

    for (int i=0; i<count; i++)
    {
        if (ans[i] >= '0' && ans[i] <= '9')
        {
            printf("%c", ans[i]);
        }
    }
    printf("\n");
}

int main(void)
{
    list_t *head1 = (node_t *)malloc(sizeof(node_t));
    list_t *head2 = (node_t *)malloc(sizeof(node_t));
    list_t *tail1;
    list_t *tail2;
    
    tail1 = create(head1);
    tail2 = create(head2);
    plus(tail1, tail2);
    
    return 0;
}