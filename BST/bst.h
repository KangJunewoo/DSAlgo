#if !defined(_BST_DEFINITION)
#define _BST_DEFINITION

typedef int element;
typedef struct _Node
{
    element v;
    struct _Node *l, *r;
} Node;

#endif // _BST_DEFINITION