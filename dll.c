#include <stdlib.h>
#include <stdio.h>
#define uint unsigned int

struct node
{
  struct node * rev;
  struct node * fwd;
  int value;
};

typedef struct node Node;

/* node operations */
void initNode (Node * p);

struct list
{
  Node * head;
  Node * tail;
  int size;
};

int println (char * str)
{
  return printf("%s\n", str);
}

typedef struct list List;

/* list operations */
List initList ();
int append (List * p, int i);
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

int main (int argc, char ** argv)
{
  printf("Beginning Doubly Linked List Test\n");

  //create a new list
  List list = initList();

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      append(&list, atoi(argv[i]));
    }
  }

  printf("\tFinal Size of list: %u\n", list.size);

  printf("Destroying and freeing list\n");
  destroyList(&list);

  exit(0);
}

List initList ()
{
  List l;
  l.head = l.tail = NULL;
  l.size = 0;
  return l;
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

//TODO determine which should be used [initNode or newNode]
void initNode (Node * p)
{
  p->fwd = NULL;
  p->value = 0xDEADBEEF;
  p->rev = NULL;
}

Node newNode ()
{
  Node ret;

  ret.fwd = NULL;
  ret.value = 0xDEADBEEF;
  ret.rev = NULL;

  return ret;
}

int isEmpty (List * listPtr)
{
  return listPtr->size == 0;
}

int append (List * listPtr, int i)
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
  return 0;
}

//deletes all occurences of a value in the list
int deleteOcc (List * listPtr, int val)
{
  //Node * itr = listPtr->head;

  /* FIXME impl deleteNode
  while(itr)
  {
    Node * next = itr->fwd;
    if (itr->value == val)
    {
      deleteNode(itr);
    }
    itr = next;
  }
  */
  return 0;
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

  if (listPtr->size == 1)
  {
    return headVal;
  }
  else
  {
    List decapt = initList();
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

int getVal (List * listPtr, int index)
{
  return get(listPtr,index)->value;
}
