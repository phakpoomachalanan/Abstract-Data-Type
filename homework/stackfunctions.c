#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node_t;

typedef node_t stack_t;

void print(stack_t *s) {
    stack_t *node = s;
    while ( node!=NULL)
    {
        printf("%c ",node->data);
        node = node->next;
    }
        
}

stack_t *push(stack_t *s,int value) {
    
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));

    node->data = value;
    node->next = NULL;
    if (s != NULL) {
        node->next = s;
    }    
    s = node;
    
    return s;
}

stack_t *pop(stack_t *s) {
    stack_t *node = s;
    //printf("pop\n");
    if (s !=NULL)
        s = node->next;
        free(node);
        
    
    return s;
}

void empty(stack_t *s) {
    if (s == NULL) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack is not empty.\n");
    }
}


void size(stack_t *s) {
    stack_t *node = s;
    int c = 0;
    while ( node!=NULL)
    {
        c++;
        node = node->next;
    }
    printf("%d\n",c);
}

void top(stack_t *s) {
    if (s != NULL) {   
        printf("%d\n",s->data);
    }
    else
    {
        printf("Stack is empty.\n");
    }
    
}






int main(void) {
    stack_t *s = NULL;
    int n,i,command,value;

    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&command);
        switch (command)
        {
        case 1:
            scanf("%d",&value);
            s = push(s,value);
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