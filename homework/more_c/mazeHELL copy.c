#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xFin,yFin;
int dim;
//must use as recursive
int traverseMaze(char **a, int y, int x)
{
    //printf("%d%d ",x,y);
    
    //dont go back too far
    if (a[y][x] != 'S')    
        a[y][x] = '.';

    //look for fin
    if (x+1 < dim && y==yFin && x+1 == xFin)
    {
        a[y][x] = '.';
        return 1;
    }
    else if (y+1 < dim && y+1==yFin && x == xFin)
    {
        a[y][x] = '.';
        return 1;
    }
    else if (x-1 >= 0 && y==yFin && x-1 == xFin)
    {
        a[y][x] = '.';
        return 1;
    }
    else if (y-1 >= 0 && y-1==yFin && x == xFin)
    {
        a[y][x] = '.';
        return 1;
    }
    //right
    if (x+1 < dim && a[y][x+1] == ' ' && traverseMaze(a, y, x+1))   //(next space is in boundary and isnt a wall and dont need to backtrack)
    {
        if (a[y][x] != 'S')     //dont overwrite start block
            a[y][x] = '.';      //place '.' on current space and move on
    }
    //down
    else if (y+1 < dim && a[y+1][x] == ' ' && traverseMaze(a, y+1, x))
    {
        if (a[y][x] != 'S') 
            a[y][x] = '.';
    }
    //left
    else if (x-1 >= 0 && a[y][x-1] == ' ' && traverseMaze(a, y, x-1))
    {
        if (a[y][x] != 'S') 
            a[y][x] = '.';
    }
    //up
    else if (y-1 >= 0 && a[y-1][x] == ' ' && traverseMaze(a, y-1, x))
    {
        if (a[y][x] != 'S') 
            a[y][x] = '.';
    }
    //backtrack
    else
    {
        if (a[y][x] != 'S') 
            a[y][x] = ' ';
        return 0;
    }

    return 1;
}

int main() {
    int i,j;
    char trash;
    scanf("%d%c",&dim,&trash);
    char **a = (char **)malloc(sizeof(char *)*dim);
    for ( i=0; i<dim; i++)
    {
    a[i] = (char *)malloc(sizeof(char)*dim);
    }
    
    for (i = 0; i < dim; i++)
    {
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
            }
            if (a[i][j]=='G')
            {
                xFin = j;
                yFin = i;                 
            }
        }
        
    }

    traverseMaze(a,yStart,xStart);
    for (int i = 0; i < dim; i++)
    {
        printf("%s\n",a[i]);        
    }
    
    return 0;
}
//why did this take 2 whole days to finish why is this so hard why why WHY