struct list
{
  Node * head;
  Node * tail;
  int size;
};

typedef struct list List;

/* list operations */
void initList (List * p);
uint append (List * p, int i);
Node * find (List * p, int i);
int contains   (List * p, int i);
int deleteOcc (List * p, int i);
int removeDups(List * p, int i);
void deleteNode (Node * p);
int isEmpty(List * p);
int max (List * p);
int min (List * p);
Node * get (List * p, int index);
int set (List * p, int index, int val);
int first (List * p);
int last (List * p);
void destroyList (List * p);
List * tail (List * p);

void initList (List * listPtr)
{
  listPtr->head = listPtr->tail = NULL;
  listPtr->size = 0;
}

List * newList ()
{
  List * p = malloc(sizeof(List));
  initList(p);
  return p;
}

void destroyList (List * listPtr)
{
  if (listPtr->size > 0)
  {
    Node * itr = listPtr->head;

    while (itr)
    {
      Node * next = itr->fwd;
      //destroyNode(itr); TODO
      free(itr);
      itr = next;
    }
    listPtr->size = 0;
  }
}

int isEmpty (List * listPtr)
{
  return listPtr->size == 0;
}
uint append (List * listPtr, int i)
{
  printf("Appending a new Node with value %d\n", i);
  Node * newNode = malloc(sizeof(Node));
  initNode(newNode);
  newNode->value = i;
  if (listPtr->tail == NULL)
  {
    listPtr->head = listPtr->tail = newNode;
  }
  else
  {
    newNode->rev = listPtr->tail;
    listPtr->tail->fwd = newNode;
    listPtr->tail = newNode;
  }
  listPtr->size++;
  return listPtr->size;
}
//deletes all occurences of a value in the list
int deleteOcc (List * listPtr, int val)
{
  Node * itr = listPtr->head;
  uint deleteCount = 0;
  while(itr)
  {
    Node * next = itr->fwd;
    if (itr->value == val)
    {
      deleteNode(itr);
      deleteCount++;
    }
    itr = next;
  }
  return deleteCount;
}

void deleteNode (Node * nodePtr)
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

Node * find (List * listPtr, int val)
{
  Node * itr = listPtr->head;

  while(itr)
  {
    if (itr->value == val)
    {
      return itr;
    }
    itr = itr->fwd;
  }

  return NULL;
}

int contains (List * listPtr, int val)
{
  return (find(listPtr, val) != NULL);
}

//yay recursive solution!
int min (List * listPtr)
{
  int headVal = listPtr->head->value;

  if (listPtr->size < 1)
  {
    return 0x0DEADBEEF;
  }
  else if (listPtr->size == 1)
  {
    return headVal;
  }
  else
  {
    List decapt;
    decapt.head = listPtr->head->fwd;
    decapt.tail = listPtr->tail;
    decapt.size = listPtr->size - 1;
    int tailMin = min(&decapt);
    return headVal < tailMin ? headVal : tailMin;
  }
}

Node * get (List * listPtr, int index)
{
  Node * itr = listPtr->head;

  while (itr && index--)
  {
    itr = itr->fwd;
  }

  return itr;
}

int first (List * listPtr)
{
  if (listPtr && listPtr->head)
  {
    return listPtr->head->value;
  }
  else
  {
    return 0x0DEADBEEF;
  }
}

int last (List * listPtr)
{
  if (listPtr && listPtr->tail)
  {
    return listPtr->tail->value;
  }
  else
  {
    return 0x0DEADBEEF;
  }
}
