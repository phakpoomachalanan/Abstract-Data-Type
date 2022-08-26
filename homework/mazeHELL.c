#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xFin,yFin;
int dim;

int traverseMaze(char **a , int **history ,int y,int x) {
    printf("asdfasdfasdf %d %d\n",x,y);
    
    if((y==yFin) && (x==xFin)) {
        printf("fin\n");
        return 1;
    }
    
    if(y>=0 && x>=0 && y<dim && x<dim && history[y][x] == 0 && a[y][x] == ' '){
        printf("hi\n");
        history[y][x] = 1;
        //down
        if(traverseMaze(a,history,y+1, x))
            printf("d\n");
            return 1;
        //right
        if(traverseMaze(a,history,y, x+1))
            printf("r\n");
            return 1;
        //up
        if(traverseMaze(a,history,y-1, x))
            printf("u\n");
            return 1;
        //left
        if(traverseMaze(a,history,y, x-1))
            printf("l\n");
            return 1;
        //backtrack
        history[y][x] = 0;
        printf("backtrack\n");
        return 0;
    }
    return 0;
}

int main() {
    //delete " = 12" when done
    scanf("%d",&dim);
    int i,j;
    char str[dim];
    char trash;
    char **a = (char **)malloc(sizeof(char *)*dim);
    for ( i=0; i<dim; i++){
    a[i] = (char *)malloc(sizeof(char)*dim);
    }
    
    for (i = 0; i < dim; i++){
        //printf("%d\n",i);
        scanf("%[^\n]%c", a[i], &trash);
        
    }
   

    int xStart,yStart;
    for ( i = 0; i < dim; i++)
    {
        for ( j = 0; j < dim; j++)
        {
            if (a[i][j]=='S')
            {
                xStart = j;
                yStart = i;
                a[i][j]=' ';
                 
            }
            if (a[i][j]=='G')
            {
                xFin = j;
                yFin = i;
                 
            }
        }
        
    }
    
    int **history = (int **)malloc(sizeof(int *)*dim);
    for ( i=0; i<dim; i++){
    history[i] = (int *)malloc(sizeof(int)*dim);
    }
    
    for ( i = 0; i < dim; i++)
    {
        for ( j = 0; j < dim; j++)
        {
            history[i][j] = 0;
        }
    }

    traverseMaze(a,history,yStart,xStart);
    for (int i = 0; i < dim; i++)
    {
        for ( j = 0; j < dim; j++)
        {
            printf("%d",history[i][j]);
            if (j%(dim-1)==0 && j!=0) {
                printf("\n");
            }
        }
        
    }
    
    return 0;
}
