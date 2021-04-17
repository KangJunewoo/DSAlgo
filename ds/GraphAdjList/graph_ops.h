#if !defined(_GRAPH_OPS)
#define _GRAPH_OPS
#include "env.h"
#include "graph.h"

void initGraph(Graph *g);
void insertVertex(Graph *g, int v);
void insertEdge(Graph *g, int vFrom, int vTo);
void printGraph(Graph *g);
void dfs(Graph *g, int vStart);
void bfs(Graph *g, int vStart);
#endif // _GRAPH_OPS
