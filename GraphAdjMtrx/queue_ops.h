#if !defined(_QUEUE_OPS)
#define _QUEUE_OPS

#include "env.h"
#include "queue.h"

void initQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);

void enqueue(Queue *q, element v);
element dequeue(Queue *q);

#endif // _QUEUE_OPS