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

Node * newNode ()
{
  Node * ret = malloc(sizeof(Node));
  initNode(ret);
  return ret;
}
