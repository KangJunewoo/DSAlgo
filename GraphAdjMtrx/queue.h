#if !defined(_QUEUE)
#define _QUEUE

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct _Queue
{
    element q[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

#endif // _QUEUE
