struct list
{
  Node * head;
  Node * tail;
  int size;
};

typedef struct list List;

/* list operations */
void initList (List * p);               //implemented
uint append (List * p, int i);          //implemented
Node * find (List * p, int i);          //implemented
int contains   (List * p, int i);       //implemented
int deleteOcc (List * p, int i);        //implemented
int removeDups(List * p, int i);        //TODO
int isEmpty(List * p);                  //implemented
int max (List * p);                     //TODO
int min (List * p);                     //implemented
Node * get (List * p, int index);       //implemented
int set (List * p, int index, int val); //TODO
int first (List * p);                   //implemented
int last (List * p);                    //implemented
void destroyList (List * p);            //implemented
List * tail (List * p);                 //TODO
List * clone (List * p);                //TODO
void sort (List * p);                   //TODO
List * sorted (List * p);               //TODO

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
      destroyNode(itr);
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
      destroyNode(itr);
      deleteCount++;
    }
    itr = next;
  }
  listPtr->size -= deleteCount;
  return deleteCount;
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

  if (listPtr->size == 0)
  {
    printf("Cannot find minimum of an empty list!\n");
    exit(1);
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
    printf("Cannot find first value in an empty list!\n");
    exit(1);
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
    printf("Cannot find last value in an empty list!\n");
    exit(1);
  }
}
