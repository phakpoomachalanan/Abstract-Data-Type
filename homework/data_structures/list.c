#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}stack_t;



void get(stack_t *startNode) {
    
}

stack_t *append(stack_t *startNode)
{
    int input = 1;
    
    stack_t *nextNode = NULL;
    
    if (startNode == NULL) {
        stack_t *newNode = NULL;
        newNode = malloc(sizeof(stack_t));
        if (newNode != NULL) {
            newNode->next = NULL;
            newNode->data = input;
            
        }
    }
    else {

    }
    return ;
}


void show(stack_t *startNode) {
    while (startNode != NULL) 
        printf("%d ", startNode->data);
        startNode = startNode->next;
}




stack_t *reverse(stack_t *startNode) {
    
}




stack_t *cut(stack_t *startNode) {
    
}



int main(void) {
    stack_t *startNode;
    int n,i;
    char command;

    startNode = NULL;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c",&command);
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