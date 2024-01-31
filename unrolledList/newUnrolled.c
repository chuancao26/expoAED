#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  struct node* next;
  int* data;
  int cantidad;
} node;
typedef struct UnrollLinkList
{
  node* head;
  node* tail;
  int cantNodos;
  int capacidad;
} UnrollLinkList;

UnrollLinkList* initUnrollLinkList(int capacidad)
{
  UnrollLinkList* new = malloc(sizeof(UnrollLinkList));
  new -> head = NULL;
  new -> tail = NULL;
  new -> cantNodos = 0;
  new -> capacidad = capacidad + 1;
  return new;
}
node* makeNewNodo(int capacidad)
{
  node* newNode = malloc(sizeof(node));
  newNode -> next = NULL;
  newNode -> cantidad = 0;
  newNode -> data = malloc(sizeof(int) * capacidad);
  return newNode;
}
void insert(UnrollLinkList* list, int x, int remanente)
{
  if (!list -> head)
  {
    list -> head  = makeNewNodo(list -> capacidad);
    list -> head -> data[list -> head -> cantidad++] = x;
    list -> tail = list -> head;
    list -> cantNodos++;
    return;
  }
  if(list -> tail -> cantidad + 1 < list -> capacidad)
    list -> tail -> data[list -> tail -> cantidad++] = x;
  else
  {
   node* newNodo = makeNewNodo(list -> capacidad);
   int j = 0;
   for (int i = list -> tail -> cantidad / 2 + 1 + (remanente > 0); i <list -> tail -> cantidad; i++)
     newNodo -> data[j++] = list -> tail -> data[i];
   list -> cantNodos++;
   newNodo -> data[j++] = x;
   newNodo -> cantidad = j;
   list -> tail -> cantidad = list -> tail -> cantidad / 2 + 1 + (remanente > 0);
   list -> tail -> next = newNodo;
   list -> tail = newNodo;
  }
}
int pop(node* head, int pos)
{
  int tmp = head -> data[pos];
  for (int i = pos; i < head -> cantidad - 1; i++)
  {
    head -> data[i] = head -> data[i + 1];
  }
  head -> cantidad--;
  return tmp;
}
void mergeNode(node* left, node* right)
{
  for (int i = 0; i < right -> cantidad; i++)
  {
    left -> data[i + left -> cantidad] = right -> data[i];
  }
  left -> cantidad += right -> cantidad;
  left -> next = left -> next -> next;
  free(right -> data);
  free(right);
}
void delete(UnrollLinkList* list, int x)
{
  node* current = list -> head;
  while(current)
  {
    for (int i = 0; i < current -> cantidad; i++)
    {
      if (current -> data[i] == x)
      {
	pop(current, i);
        while(current -> cantidad < (list -> capacidad / 2 + 1) && current -> next)
  	  current -> data[current -> cantidad++] = pop(current -> next, 0);
        if(current -> next && current -> next -> cantidad < (list -> capacidad / 2 + 1))
        {
	  mergeNode(current, current -> next);
	  list -> cantNodos--;
        }
	return;
      }	
    }
    current = current -> next;
  }
}

void traversal(UnrollLinkList* list)
{
  node* current = list -> head;
  for (int i = 0; i < list -> cantNodos; i++)
  {
    for (int j = 0; j < current -> cantidad; j++)
      printf("%d ", current -> data[j]);
    printf("\n");
    current = current -> next;
  }
}
int search(UnrollLinkList* list, int x)
{
  node* current = list -> head;
  for (int i = 0; i < list -> cantNodos; i++)
  {
    for(int j = 0; j < current -> cantidad; j++)
      if (current -> data[j] == x) return 1;
    current = current -> next;
  }
  return 0;
}
/*
int main()
{
  UnrollLinkList* list = initUnrollLinkList(5);
  for (int i = 1 ; i < 12; i++)
  {
    printf("%s %d\n", "Insertando el valor: ", i);
    insert(list, i);
    traversal(list);
  }

  printf("%s %d\n", "Eliminando el valor: ", 1);
  delete(list, 1);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 3);
  delete(list, 3);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 9);
  delete(list, 9);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 10);
  delete(list, 10);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 11);
  delete(list, 11);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 4);
  delete(list, 4);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 5);
  delete(list, 5);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 2);
  delete(list, 2);
  traversal(list);
  printf("%s %d\n", "Eliminando el valor: ", 8);
  delete(list, 8);
  traversal(list);

  delete(list, 2);
  delete(list, 1);
  delete(list, 17);
  delete(list, 11);
  delete(list, 9);
  delete(list, 5);
  delete(list, 8);
  delete(list, 16);
  delete(list, 18);
  delete(list, 19);
  delete(list, 15);
  delete(list, 7);

  printf("cantidad de nodos: %d\n", list -> cantNodos);

  printf("Borrado\n");
  traversal(list);
  delete(list, 2);
  printf("Borrado\n");
  traversal(list);
  delete(list, 1);
  printf("Borrado\n");
  traversal(list);
  delete(list, 3);
  printf("Borrado\n");
  traversal(list);
  delete(list, 4);

  return 0;
}
*/
