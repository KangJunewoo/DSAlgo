#if !defined(_GRAPH_OPS)
#define _GRAPH_OPS
#include "env.h"
#include "graph.h"

void initGraph(Graph *g);
void insertVertex(Graph *g, element v);
void insertEdge(Graph *g, int vFrom, int vTo);
void bfs(Graph *g, element v);
void dfs(Graph *g, element v);

#endif // _GRAPH_OPS
