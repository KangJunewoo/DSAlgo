#include "env.h"
#include "queue.h"
#include "queue_ops.h"

void initQueue(Queue *q)
{
    q->front = q->rear = 0;
}
int isQueueEmpty(Queue *q)
{
    return (q->front == q->rear);
}

int isQueueFull(Queue *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, element v)
{
    if (isQueueFull(q))
        error("큐가 가득 찼습니다.\n");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->q[q->rear] = v;
}
element dequeue(Queue *q)
{
    if (isQueueEmpty(q))
        error("큐가 비어있습니다.\n");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->q[q->front];
}