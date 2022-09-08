#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *left;
struct node *right;
} node_t;
typedef node_t bst_t;
// Write your code here
// ...

int find(bst_t *t,int value) {
    int f = 0;
    if (t == NULL)
    {
        if (f == 1)
        {
            return 1;
        }
        return 0;
    } 
    if (value == t->data)
    {
        return 1;
    }
    if (value < t->data)
    {
        if (f == 1)
        {
            return 1;
        }
        f = find(t->left,value);
    }
    if (value > t->data)
    {
        if (f == 1)
        {
            return 1;
        }
        f = find(t->right,value);
    }
    return f;   

}
bst_t *findpos(bst_t *t,int value) {
    
    if (t == NULL)
    {
        return t;
    } 
    if (value == t->data)
    {
        return t;
    }
    if (value < t->data)
    {
        return findpos(t->left,value);
    }
    if (value > t->data)
    {
        return findpos(t->right,value);
    }  

}
bst_t *findparpos(bst_t *t,int value) {
    
    if (t == NULL)
    {
        return t;
    } 
    if (t->left != NULL && value == t->left->data)
    {
        return t;
    }
    if (t->right != NULL && value == t->right->data)
    {
        return t;
    }
    if (value < t->data)
    {
        return findparpos(t->left,value);
    }
    if (value > t->data)
    {
        return findparpos(t->right,value);
    }  

}
int find_min(bst_t *t) {
    if (t == 0)
    {
        return 0;
    }
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t->data;
}
int find_max(bst_t *t) {
    if (t == 0)
    {
        return 0;
    }
    while (t->right != NULL)
    {
        t = t->right;
    }
    return t->data;
}

bst_t *insert(bst_t *t,int value) {   
    if (find(t,value))
    {
        return t;
    }
    else {
        bst_t *newnode = (bst_t*)malloc(sizeof(bst_t));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        if (t == NULL)
        {
            return newnode;
        }
        bst_t *tmp = t;
        while (tmp != NULL)
        {
            if (value < tmp->data)
            {
                if (tmp->left == NULL)
                {
                    tmp->left = newnode;
                    return t;
                }
                tmp = tmp->left;
            }
            if (value > tmp->data)
            {
                if (tmp->right == NULL)
                {
                    tmp->right = newnode;
                    return t;
                }
                tmp = tmp->right;
            }
        }
    }
    return t;
}

int is_leaf(bst_t *t) {
    if (t->left == NULL && t->right == NULL) {
        return 1;
    } else {
        return 0;
    }
}


bst_t *delete(bst_t *t,int value) {
    bst_t *pos = findpos(t,value);
    bst_t *parpos = findparpos(t,value);
    //case 1 ; is leaf
    if (pos->left == NULL && pos->right == NULL)
    {
        if (parpos->left != NULL)
        {
            parpos->left = NULL;
        }
        if (parpos->right != NULL)
        {
            parpos->right = NULL;
        }
        
        free(pos);
        return t;
    }
    
    
    //case 2 ; 1 child
    if ((pos->left == NULL) != (pos->right == NULL))
    {
        if (pos->left != NULL)
        {
            parpos->left = pos->left;
        }
        if (pos->right != NULL)
        {
            parpos->right = pos->right;
        }
        free(pos);
        return t;
    }
    //case 3 ; 2 children
    if (pos->left != NULL && pos->right != NULL)
    {
        bst_t *rightroot = pos->right;
        int minvalue = find_min(rightroot);
        delete(t,minvalue);
        pos->data = minvalue;
    }
    return t;
}


int main(void) {
bst_t *t = NULL;
int n, i;
int command, data;
scanf("%d", &n);
for (i=0; i<n; i++) {
scanf("%d", &command);
switch (command) {
case 1:
scanf("%d", &data);
t = insert(t, data);
break;
case 2:
scanf("%d", &data);
t = delete(t, data);
break;
case 3:
scanf("%d", &data);
printf("%d\n", find(t, data));
break;
case 4:
printf("%d\n", find_min(t));
break;
case 5:
printf("%d\n", find_max(t));
break;
}
}
return 0;
}