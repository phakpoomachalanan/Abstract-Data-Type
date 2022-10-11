#include <stdio.h>
#include <stdlib.h>

typedef struct path
{
    int weight;
    int visit;
    int before;
}
path_t;

void reset_path(path_t* path, int n);
int get_weight(path_t* path, int** matrix, int start, int stop, int n, int count);

int main(void)
{
    int     n, m, p;
    int     u, v, w;
    int     i, j, temp;
    int     start, stop;
    int**   matrix = (int**)malloc(sizeof(int*) * n);
    path_t* path = (path_t*)malloc(sizeof(path_t) * n);

    scanf("%d %d %d", &n, &m, &p);

    for (i=0; i<n; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        for (j=0; j<n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (i=0; i<n; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        matrix[u][v] = w;
        matrix[v][u] = w;
    }
    for (i=0; i<p; i++)
    {
        scanf("%d %d", &start, &stop);
        reset_path(path, n);
        printf("%d\n", get_weight(path, matrix, start, stop, n, 0));
    }

    return 0;
}

void reset_path(path_t* path, int n)
{
    int i;

    for (i=0; i<n; i++)
    {
        path[i].before = 0;
        path[i].visit = 0;
        path[i].weight = 0;
    }
}

int get_weight(path_t* path, int** matrix, int start, int stop, int n, int count)
{
    int min = 999999999;
    int i, explore;

    path[start].visit = 1;

    printf("");
    if (count >= 2*n)
    {
        if (path[stop].weight != 0)
        {
            return path[stop].weight;
        }
        return -1;
    }

    for (i=0; i<n; i++)
    {
        if (matrix[start][i] != 0)
        {
            if (matrix[start][i] < min && path[i].visit == 0)
            {
                min = matrix[start][i];
                explore = i;
            }
            if (path[i].weight == 0 && path[i].visit == 0)
            {
                path[i].weight += path[start].weight + matrix[start][i];
            }
            else if (matrix[start][i]+path[start].weight < path[i].weight)
            {
                path[i].weight = path[start].weight + matrix[start][i];
            }
        }
    }
    
    if (explore >= n)
    {
        return get_weight(path, matrix, path[start].before, stop, n, count+1);
    }
    else
    {
        path[explore].before = start;
        return get_weight(path, matrix, explore, stop, n, count+1);
    }
}