#if !defined(_GRAPH)
#define _GRAPH
#define MAX_VERTICES 50
#include "env.h"

typedef struct _Graph
{
    int vn;
    int mtrx[MAX_VERTICES][MAX_VERTICES];
} Graph;

element visitT[MAX_VERTICES];

#endif // _GRAPH
