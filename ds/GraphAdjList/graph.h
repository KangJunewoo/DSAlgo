#if !defined(_GRAPH)
#define _GRAPH
#define MAX_VN 50
#include "env.h"

typedef struct _Node
{
    int v;
    struct _Node *l;
} Node;

typedef struct _Graph
{
    int vn;
    Node *adjList[MAX_VN];
} Graph;

int visitT[MAX_VN];

#endif // _GRAPH
