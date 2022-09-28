#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node *next;
}stack_t;

stack_t *push(stack_t *s,int parenthesis) {
    printf("hi");
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));

    if (parenthesis == '(' || parenthesis == '[' || parenthesis == '{' )    
        node->data = parenthesis;
        node->next = NULL;
        if (s != NULL) {
            node->next = s;
        }    
        s = node;
    
    
    return s;
}

void print(stack_t *s) {
    stack_t *node = s;
    while ( node!=NULL)
    {
        printf("%c",node->data);
        node = node->next;
    }
        
}

int main(){
    int length;
    scanf("%d",&length);
    char *str;
    str = (char*)malloc(sizeof(char)*(length+1));
    scanf("%s",str);
    
    stack_t *s = NULL;    
    
    for (int i = 0; i < length; i++)
    {
        //printf("%d",i);
        s = push(s,str[i]);
    }
    print(s);

    return 0;
}