#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node *next;
}stack_t;

stack_t *push(stack_t *s,int parenthesis) {
    
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));

    node->data = parenthesis;
    node->next = NULL;
    if (s != NULL) {
        node->next = s;
    }    
    s = node;
    
    return s;
}

stack_t *pop(stack_t *s) {
    stack_t *node = s;
    s = node->next;
    free(node);
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
 
int check(stack_t *s,char parenthesis) {
    stack_t *node = s;
    while ( node!=NULL)
    {
        print(s);
        if (node->next == NULL) {   
            if (node->data == '(' && parenthesis == ')') {
                pop(s);
                return 1;
            }
            else if (node->data == '[' && parenthesis == ']') {
                pop(s);
                return 1;
            }
            else if (node->data == '{' && parenthesis == '}') {
                pop(s);
                return 1;
            }
            else {
                return 0;
            }
        }
        node = node->next;
    }
    return 1;
}

int main(){
    int length;
    scanf("%d",&length);
    char *str;
    str = (char*)malloc(sizeof(char)*(length+1));
    scanf("%s",str);
    int out = 0;
    stack_t *s = NULL;    
    
    for (int i = 0; i < length; i++)
    {
        if (s!=NULL){
            out = check(s,str[i]);
        }
        if (out!=1)   
            s = push(s,str[i]);
        
    }
    printf("%d",out);
    return 0;
}