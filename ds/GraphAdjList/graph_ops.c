#include <stdio.h>
#include <stdlib.h>
#include "env.h"
#include "graph.h"
#include "graph_ops.h"
#include "queue.h"
#include "queue_ops.h"

void initGraph(Graph *g)
{
    int v;
    g->vn = 0;
    for (v = 0; v < MAX_VN; v++)
    {
        g->adjList[v] = NULL;
    }
}
void insertVertex(Graph *g, int v)
{
    if (g->vn >= MAX_VN)
    {
        error("vn 초과");
    }
    g->vn++;
}
void insertEdge(Graph *g, int v1, int v2)
{
    Node *node; // edge를 만들 때 실제 메모리를 할당하나보다. 그래프의 표현 방식을 생각해보면 당연함.
    if (v1 >= g->vn || v2 >= g->vn)
    {
        error("잘못된 vFrom or 잘못된 vTo");
    }
    node = (Node *)malloc(sizeof(Node));
    node->v = v2;             // 일단 v2로 잡고
    node->l = g->adjList[v1]; // v2가 연결된 곳은 v1의 adjList..?
    g->adjList[v1] = node;    // v1은 노드? 이 부분 잘 이해가 안간다.
}
void printGraph(Graph *g)
{
    for (int i = 0; i < g->vn; i++)
    {
        Node *p = g->adjList[i];
        printf("%d의 인접리스트 ", i);
        while (p != NULL)
        {
            printf("-> %d ", p->v);
            p = p->l;
        }
        printf("\n");
    }
}

void bfs(Graph *g, int v)
{
    Node *p;
    Queue q;

    initQueue(&q);
    visitT[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);
    while (!isQueueEmpty(&q))
    {
        v = dequeue(&q);
        for (p = g->adjList[v]; p; p = p->l)
        {
            if (!visitT[p->v])
            {
                visitT[p->v] = TRUE;
                printf("%d ", p->v);
                enqueue(&q, p->v);
            }
        }
    }
}