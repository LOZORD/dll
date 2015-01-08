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
};

int println (char * str)
{
  return printf("%s\n", str);
}

typedef struct list List;

/* list operations */
void initList (List * p);
int append (List * p, int i);
int find   (List * p, int i);
int deleteOcc (List * p, int i);
int deleteNode (Node * p);
int isEmpty(List * p);
int max (List * p);
int min (List * p);
int get (List * p, int index);
int set (List * p, int index, int val);
int first (List * p);
int last (List * p);
void destroyList (List * p);
uint size (List * p);

//FIXME
uint size (List * listPtr)
{
  //return (uint)(listPtr->tail - listPtr->head);
  if (listPtr->head == NULL)
  {
    return 0;
  }
  else
  {
    return (uint)(listPtr->tail - listPtr->head) + 1;
  }
}

int main (int argc, char ** argv)
{
  printf("Beginning Doubly Linked List Test\n");

  //create a new list
  List list;
  initList(&list);

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      append(&list, atoi(argv[i]));
    }
  }

  printf("Size of list: %u\n", size(&list));

  printf("Destroying and freeing list\n");
  destroyList(&list);

  exit(0);
}

void initList (List * listPtr)
{
  listPtr->head = listPtr->tail = NULL;
}

void destroyList (List * listPtr)
{
  if (size(listPtr) > 0)
  {
    Node * itr = listPtr->head;

    while (itr)
    {
      Node * next = itr->fwd;
      free(itr);
      itr = next;
    }
  }
}

void initNode (Node * p)
{
  p->fwd = NULL;
  p->value = 0xDEADBEEF;
  p->rev = NULL;
}

int isEmpty (List * listPtr)
{
  return size(listPtr) == 0;
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
    listPtr->tail = newNode;
  }
  return 0;
}
