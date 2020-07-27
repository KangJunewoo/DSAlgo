#if !defined(GRAPH_H)
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode{Visited, NotVisited};

typedef int ElementType;

/**
 * 자구수업때 기억나는 그래프는
 * a - b - c - d
 * b - a - d
 * c - a
 * d - a - b
 * 
 * 굳이 아래와 같이 해야하나?
 * 그냥 edge 없이 선언해도 될듯한ㄷ..
*/

typedef struct vertex{
  ElementType Data;
  
  int Visited; // traverse에서 사용
  int Index; // 최단경로 탐색에서 사용.

  struct vertex* Next;
  struct edge* AdjacencyList;
} Vertex;

typedef struct edge{
  int Weight;
  struct edge* Next;
  struct vertex* From;
  struct vertex* Target;
} Edge;

typedef struct graph{
  struct vertex* Vertices;
  int VertexCount;
} Graph;

Graph* createGraph();
void destroyGraph(Graph* G);

Vertex* createVertex(ElementType Data);
void destroyVertex(Vertex* V);

Edge* createEdge(Vertex* From, Vertex* Target, int Weight);
void destroyEdge(Edge* E);

void addVertex(Graph* G, Vertex* V);
void addEdge(Vertex* V, Edge* E);
void printGraph(Graph* G);

#endif // GRAPH_H
