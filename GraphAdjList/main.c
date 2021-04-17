#include "graph.h"
#include "graph_ops.h"
#include "queue.h"
#include "queue_ops.h"
#include "env.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Graph *g;
    g = (Graph *)malloc(sizeof(Graph));
    initGraph(g);
    for (int i = 0; i < 4; i++)
    {
        insertVertex(g, i);
    }
    insertEdge(g, 0, 1);
    printGraph(g);
    // bfs(g, 0);
    printf("\n");
    insertEdge(g, 0, 2);
    printGraph(g);
    // bfs(g, 0);
    printf("\n");
    insertEdge(g, 0, 3);
    printGraph(g);
    // bfs(g, 0);
    printf("\n");
    insertEdge(g, 1, 2);
    printGraph(g);
    // bfs(g, 0);
    printf("\n");
    insertEdge(g, 2, 3);
    printGraph(g);
    // bfs(g, 0);
    printf("\n");

    free(g);
    return 0;
}