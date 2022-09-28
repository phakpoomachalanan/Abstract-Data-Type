#include <stdio.h>
#include <stdlib.h>
#include "week9.h"
#ifndef __avl_tree__
typedef struct node {
int data;
int height;
struct node *left;
struct node *right;
} node_t;
typedef node_t avl_t;
#endif
// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
// ...
int find(avl_t *t,int value) {
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
int height(avl_t *t) {
    int hl;
    int hr;
    if (t == NULL)
    {
        return -1;
    } 
    hl = height(t->left);
    hr = height(t->right);
    if (hl>hr) {
        return hl+1;
    } else {
        return hr+1;
    }
}
avl_t *findpos(avl_t *t,int value) {
    
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
avl_t *findparpos(avl_t *t,int value) {
    
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
avl_t *rotate_left (avl_t *t) {
    //printf("-L\n");
    avl_t *rightsub = t->right;
    avl_t *node = rightsub->left;
    rightsub->left = t;
    t->right = node;
    rightsub->height = height(rightsub);
    t->height = height(t);
    
    return rightsub;
}

avl_t *rotate_right(avl_t *t) {
    //printf("-R\n");
    avl_t *leftsub = t->left;
    avl_t *node = leftsub->right;
    leftsub->right = t;
    t->left = node;
    leftsub->height = height(leftsub);
    t->height = height(t);
    
    return leftsub;
}

avl_t *balance(avl_t *t,int value) {
    if (t != NULL) {
        if (t->data == value)
        {
            return t;
        }
        if (value < t->data)
        {
            t->left = balance(t->left, value);
        }
        else if (value > t->data)
        {
            t->right = balance(t->right, value);
        }
        printf(":%d\n",t->data);
        if (height(t->left) > 1+ height(t->right))
        {
            if (value < t->left->data) /* insert at left of left subtree */
            {
                return rotate_right(t);
            }
            else /* insert at right of left subtree */
            { 
                t->left = rotate_left(t->left);
                return rotate_right(t);
            }
        }

        if (height(t->right) > 1+ height(t->left))
        {
            if (value > t->right->data) /* insert at right of right subtree */
            {
                return rotate_left(t);
            }
            else /* insert at left of right subtree */
            {
                t->right = rotate_right(t->right);
                return rotate_left(t);
            }
        }
    }
    return t;
}

avl_t *insert(avl_t *t,int value) {
    if (find(t,value))
    {
        return t;
    }
    else {
        avl_t *newnode = (avl_t*)malloc(sizeof(avl_t));
        newnode->data = value;
        newnode->height = 0;
        newnode->left = NULL;
        newnode->right = NULL;
        if (t == NULL)
        {
            return newnode;
        }
        avl_t *tmp = t;
        while (tmp != NULL)
        {
            if (value < tmp->data)
            {
                if (tmp->left == NULL)
                {
                    tmp->left = newnode;
                    return balance(t,value);
                }
                tmp = tmp->left;
            }
            if (value > tmp->data)
            {
                if (tmp->right == NULL)
                {
                    tmp->right = newnode;
                    return balance(t,value);
                }
                tmp = tmp->right;
            }
        }
    }
    
    
}
int find_min(avl_t *t) {
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
avl_t *delete(avl_t *t,int value) {
    if (t == NULL)
    {
        return t;
    }
    if (value == t->data) //delete root
    {
        if (t->left == NULL)
        {
            avl_t *tmp = t->right;
            free(t);
            return tmp;
        }
        else if (t->right == NULL)
        {
            avl_t *tmp = t->left;
            free(t);
            return tmp;
        }
        
        int minvalue = find_min(t->right);
        t->data = minvalue;
        t->right = delete(t->right,minvalue);

    }
    else if (value < t->data) //recurse until found node with the value
    {
        t->left = delete(t->left,value);
    }
    else if (value > t->data)
    {
        t->right = delete(t->right,value);
    }
    
    return balance(t,value);
    
    
        
}






int main(void) {
avl_t *t = NULL;
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
print_tree(t);
break;
}
}
return 0;
}