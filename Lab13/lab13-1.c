#include <stdio.h>
#include <stdlib.h>

int pause = 0;

typedef struct node node_t;
typedef node_t graph_t;
typedef struct edge edge_t;

struct edge
{
    int     weight;
    int     node;
    edge_t* next;
};

struct node
{
    int     vertex;
    edge_t* edge;
};

edge_t* init_edge(int weight, int next);
edge_t* get_weight(graph_t** g, int start, int stop, int now);
void print(node_t* node);

int main(void)
{
    int       n, m, p;
    int       u, v, w;
    int       i, temp;
    int       start, stop;
    graph_t** g;
    edge_t*   edge;

    scanf("%d %d %d", &n, &m, &p);
    g = (graph_t**)malloc(sizeof(node_t*) * n);

    for (i=0; i<n; i++)
    {
        g[i] = (node_t*)malloc(sizeof(node_t));
    }
    for (i=0; i<n; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if (u > v)
        {
            temp = v;
            v = u;
            u = temp;
        }
        g[u]->vertex = u;
        edge = g[u]->edge;
        if (edge == NULL)
        {
            g[u]->edge = init_edge(w, v);
        }
        else
        {
            while (edge->next != NULL)
            {
                if (edge->weight > w)
                {
                    temp = w;
                    w = edge->weight;
                    edge->weight = temp;
                    temp = v;
                    v = edge->node;
                    edge->node = temp;
                }
                edge = edge->next;
            }
            edge->next = init_edge(w, v);
        }

    }
    for (i=0; i<p; i++)
    {
        print(g[i]);
    }
    for (i=0; i<p; i++)
    {
        //print(g[i]);
        scanf("%d %d", &start, &stop);
        edge = start < stop ? get_weight(g, start, stop, 0) : get_weight(g, stop, start, 0);
        pause = 0;
        if (edge == NULL)
        {
            printf("-1\n");
        }
    }

    return 0;
}

edge_t* init_edge(int weight, int node)
{
    edge_t* edge = (edge_t*)malloc(sizeof(edge_t));

    edge->weight = weight;
    edge->node = node;

    return edge;
}

void print(node_t* node)
{
    edge_t* next = node->edge;

    while (next != NULL)
    {
        printf("%d--%d--%d\n", node->vertex, next->weight, next->node);
        next = next->next;
    }
}
/*
int get_weight(graph_t** g, int start, int stop, int now)
{
    static int pause;
    int i, temp, weight;
    edge_t* next = g[start]->edge;

    if (g[start]->vertex == stop)
    {
        return 0;
    }
    if (next == NULL)
    {
        //pause = -1;
        return -1;
    }
    printf("%d %d %d %d\n", next->node, stop, now, pause);
    temp = get_weight(g, next->node, stop, now+next->weight);
    if (temp == 0)
    {
        pause = 1;
        return now + next->weight;
    }
    if (pause == 1)
    {
        return temp;
    }
    printf("nope %d\n", pause);
    if (next->next == NULL)
    {
        return -1;
    }
    return get_weight(g, next->next->node, stop, now+next->weight);
}
*/
edge_t* get_weight(graph_t** g, int start, int stop, int now)
{
    edge_t* next = g[start]->edge;
    edge_t* pos = NULL;

    if (pause == 1)
    {
        pause = 0;
        return next;
    }
    if (next == NULL)
    {
        return next;
    }
    if (next->node == stop)
    {
        pause = 1;
        printf("%d\n", now+next->weight);
        return next;
    }

    pos = get_weight(g, next->node, stop, now+next->weight);
    if (pos != NULL)
    {
        return pos;
    }

    if (next->next == NULL)
    {
        return NULL;
    }
    return get_weight(g, next->next->node, stop, now+next->weight);
}
