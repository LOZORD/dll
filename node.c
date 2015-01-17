#define uint unsigned int

struct node
{
  struct node * rev;
  struct node * fwd;
  //only allow for int data
  //TODO: use generics?
  int value;
};

typedef struct node Node;

/* node operations */
void initNode (Node * p)
{
  p->fwd = NULL;
  p->value = 0xDEADBEEF;
  p->rev = NULL;
}

void initNodeWithValue (Node * p, int v)
{
  initNode(p);
  p->value = v;
}

Node * newNode ()
{
  Node * ret = malloc(sizeof(Node));
  initNode(ret);
  return ret;
}

void destroyNode (Node * nodePtr)
{
  Node * prev = nodePtr->rev;
  Node * next = nodePtr->fwd;

  //if this is not the first node in the list
  if (prev != NULL)
  {
    prev->fwd = next;
  }

  //if this is not the last node in the list
  if (next != NULL)
  {
    next->rev = prev;
  }

  free(nodePtr);

  return;
}
