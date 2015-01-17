#include <stdlib.h>
#include <stdio.h>
#include "node.c"
#include "list.c"


int println (char * str)
{
  return printf("%s\n", str);
}


int main (int argc, char ** argv)
{
  printf("Beginning Doubly Linked List Test\n");

  //create a new list
  List * list = newList();

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      append(list, atoi(argv[i]));
    }
  }

  printf("\tFinal Size of list: %u\n", list->size);
  printf("\tMin of list: %d\n", min(list));

  printf("Destroying and freeing list\n");
  destroyList(list);

  exit(0);
}
