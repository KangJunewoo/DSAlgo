#include <stdio.h>
#include "env.h"
#include "graph.h"
#include "graph_ops.h"
#include "queue.h"
#include "queue_ops.h"

void initGraph(Graph *g)
{
    g->vn = 0;
    for (int r = 0; r < MAX_VERTICES; r++)
        for (int c = 0; c < MAX_VERTICES; c++)
            g->mtrx[r][c] = 0;
}

void insertVertex(Graph *g, element v)
{
    if (((g->vn) + 1) > MAX_VERTICES)
    {
        error("vertex overflow!\n");
        return;
    }
    g->vn++;
}
void insertEdge(Graph *g, int vFrom, int vTo)
{
    if (vFrom >= g->vn || vTo >= g->vn)
    {
        error("vFrom&vTo error!\n");
        return;
    }
    g->mtrx[vFrom][vTo] = 1;
    g->mtrx[vTo][vFrom] = 1;
}
void bfs(Graph *g, element v)
{
    Queue q;

    initQueue(&q);
    visitT[v] = TRUE;
    printf("%d -> ", v);
    enqueue(&q, v);
    while (!isQueueEmpty(&q))
    {
        v = dequeue(&q);
        for (int vTo = 0; vTo < g->vn; vTo++)
        {
            if (g->mtrx[v][vTo] && !visitT[vTo])
            {
                visitT[vTo] = TRUE;
                printf("%d -> ", vTo);
                enqueue(&q, vTo);
            }
        }
    }
    for (int i = 0; i < g->vn; i++)
    {
        visitT[i] = FALSE;
    }
}
void dfs(Graph *g, element v)
{
    visitT[v] = TRUE;
    printf("%d -> ", v);
    for (int vTo = 0; vTo < g->vn; vTo++)
        if (g->mtrx[v][vTo] && !visitT[vTo])
            dfs(g, vTo);
}
