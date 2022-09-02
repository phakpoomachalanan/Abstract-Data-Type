#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif
typedef struct queuenode {
    struct node *child;
    struct queuenode *next;
} queuenode_t;

typedef struct queue {
  queuenode_t *front;
  queuenode_t *rear;
} queue_t;
void enqueue(queue_t *q,tree_t *t) {
  queuenode_t *newnode = (queuenode_t *)malloc(sizeof(queuenode_t));
  newnode->next = NULL;
  newnode->child = t;
  if (q->front == NULL) {
    q->front = newnode;
    q->rear = newnode;
  } else {
    q->rear->next = newnode;
    q->rear = newnode;
  }

}                    
tree_t *dequeue(queue_t *q) {
  tree_t *tmp = q->front->child;
  queuenode_t *oldfront = q->front;
  q->front = q->front->next;
  free(oldfront);
  return tmp;
}

int height(tree_t *t) {
    if (t == NULL)
    {
        return -1;
    }
    int hl = -1;
    int hr = -1;
    if (t->left != NULL)
        hl = height(t->left);
    if (t->right != NULL)
        hr = height(t->right);
    if (hl>hr)
    {
        return hl+1;
    } else {
    return hr+1;
    }
}

int countnode(tree_t *t) {
    
    if (t == NULL)
    {
        return 0;
    }
    return (countnode(t->left)+countnode(t->right)+1);
}

int countleaf(tree_t *t) {
    
    if (t == NULL)
    {
        return 0;
    }

    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    return (countleaf(t->left)+countleaf(t->right));
    
}

int is_full(tree_t *t) {
    int f = 1;
    if (t == NULL)
    {
        return 1;
    }
    if ((t->left == NULL) != (t->right == NULL))
    {
        return 0;
    }
    
    if (t->left != NULL)
    {
        f = is_full(t->left);
    }
    if (t->right != NULL)
    {
        f = is_full(t->right);
    }
    return f;
}
int Pow(int a ,int b ) {  
    int p = 1 , i ;  
    for (i = 1;i <= b;i++ ) {  
        p = p * a ;  
    }  
    return p ;  
}  
int is_perfect(tree_t *t) {
    if (t == NULL)
    {
        return 1;
    }
    int h = height(t);
    //printf("%d %d %d %d %d\n",h,countnode(t),Pow(2,h+1)-1,countleaf(t),Pow(2,h));
    if (countnode(t) == Pow(2,h+1)-1 && countleaf(t) == Pow(2,h))
    {   
        return 1;
    } else {
        return 0;
    }
    
}
int is_complete(tree_t *t) {
    int f = 1;
    if (t == NULL)
    {
        return 1;
    }
    tree_t *tmp = t;
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    
    enqueue(q,tmp);
    while (q->front != NULL)
    {
        tree_t *tmp = dequeue(q);
        if (tmp->left != NULL) {
            if (f == 0)
            {
                return f;
            }
            enqueue(q,tmp->left);
        } else {
            f = 0;
        }
            
        
        
        
        if (tmp->right != NULL) {
            if (f == 0)
            {
                return f;
            }
            enqueue(q,tmp->right);
        } else {
            f = 0;
        }
    }
    return 1;
    
    
}

int is_degenerate(tree_t *t) {
    int f = 1;
    if (t == NULL)
    {
        return 1;
    }
    if (t->left != NULL && t->right != NULL)
    {
        return 0;
    }
    
    if (t->left != NULL)
    {
        f = is_degenerate(t->left);
    }
    if (t->right != NULL)
    {
        f = is_degenerate(t->right);
    }
    return f;

}

int is_skewed(tree_t *t) {
    tree_t *tmp = t;
    if (t == NULL)
    {
        return 1;
    }
    
    
    if (t->left != NULL && t->right == NULL)
    {
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
            if (tmp->right != NULL)
                return 0;
        }
        
    }
    
    else if (t->right != NULL && t->left == NULL)
    {
        while (tmp->right != NULL)
        {
            tmp = tmp->right;
            if (tmp->left != NULL)
                return 0;
        }
        
    }
    else 
    {
        return 0;
    }
    
    return 1;
    
}

int main(void) {
    tree_t *t = NULL;
    int  n,i;
    int parent,child;
    int branch; //0root 1left 2right

    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d",&parent,&child,&branch);
        t = attach(t,parent,child,branch);
    }

    printf("%d %d %d %d %d\n",is_full(t),is_perfect(t),is_complete(t),is_degenerate(t),is_skewed(t));
    return 0;
}