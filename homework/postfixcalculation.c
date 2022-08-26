#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    double data;
    struct node *next;
}stack_t;

void print(stack_t *s) {
    stack_t *node = s;
    while ( node!=NULL)
    {
        printf("%.2f ",node->data);
        node = node->next;
    }
        
}
stack_t *push(stack_t *s,double oprnd) {
    //printf("pushed %f\n",oprnd);
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));

    node->data = oprnd;
    node->next = NULL;
    if (s != NULL) {
        node->next = s;
    }    
    s = node;
    /*printf("current [ ");
    print(s);
    printf("]\n");*/
    return s;
}

stack_t *pop(stack_t *s) {
    stack_t *node = s;
    //printf("pop %f\n",node->data);
    s = node->next;
    free(node);
    /*printf("current [ ");
    print(s);
    printf("]\n");*/
    
    return s;
}


stack_t *operation(stack_t *s ,char oprtr) {
    stack_t *node = s;
    double x,y;
    
    if (oprtr == '+') {
        y = s->data;
        s = pop(s);
        x = s->data;
        s = pop(s);
        //printf("%f + %f = %f\n",x,y,x+y);
        s = push(s,x+y);
        
        
    }
    if (oprtr == '-') {
        y = s->data;
        s = pop(s);
        x = s->data;
        s = pop(s);
        //printf("%f - %f = %f\n",x,y,x-y);
        s = push(s,x-y);
        
        
    }
    if (oprtr == '*') {
        y = s->data;
        s = pop(s);
        x = s->data;
        s = pop(s);
        //printf("%f * %f = %f\n",x,y,x*y);
        s = push(s,x*y);
        
        
    }
    if (oprtr == '/') {
        y = s->data;
        s = pop(s);
        x = s->data;
        s = pop(s);
        //printf("%f * %f = %f\n",x,y,x/y);
        s = push(s,x/y);
        
        
    }
    /*printf("current [ ");
    print(s);
    printf("]\n");*/

    return s;
}




int main(){
    int length;
    scanf("%d",&length);
    char *str;
    str = (char*)malloc(sizeof(char)*(length+1));
    scanf("%s",str);
    
    stack_t *s = NULL;    
    
    for (int i =0;i<length;i++) {
        //printf("%f\n",(double)str[i]);
        if (str[i]=='+' || str[i]=='-'|| str[i]=='*'|| str[i]=='/') {
            s = operation(s,str[i]);
            continue;
        }
        else if (str[i] != '\n') {
            s = push(s,(double)str[i]-48);          
        }
        
    }
        
    print(s);
    return 0;
} 
