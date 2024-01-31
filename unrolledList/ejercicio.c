#include "unrolled.c"
typedef struct nodo
{
  int data;
  struct nodo* next;
} nodo;
void push(nodo** head, int x)
{
  nodo* newNodo = malloc(sizeof(nodo));
  newNodo -> data = x;
  newNodo -> next = *head;
  *head = newNodo;
}
void printNodos(nodo* head)
{
  for(head; head; head = head -> next)
  {
    printf("%d ", head -> data);
  }
  printf("\n");
}
UnrollLinkList* split(nodo* current, int k, int len)
{
  int n = len / k;
  int remanentes = len % k;
  UnrollLinkList* list = initUnrollLinkList(n * 2 - 1);
  for (int i = 0; current && (i < len - remanentes) ; current = current -> next, i++)
  {
    insert(list, current -> data);
  } 
  node* head = list -> head;
  for (current; current; current = current -> next, list -> head = list -> head -> next)
  {
    list -> head -> data[list -> head -> cantidad] = current -> data;
    list -> head -> cantidad++;
  }
  list -> head = head;
  return list;
}
int main()
{
  nodo* head = NULL;
  nodo** lastNode = &head;
  printf("----------------\n");
  printf("Inputs:\nLista enlazada:\n");
  int k = 8;
  int cant = 40;
  for (int i = 1; i < cant + 1; i++)
  {
    push(lastNode, i);
    lastNode = &((*lastNode) -> next);
  }
  printNodos(head);
  printf("k = %d\n", k);
  printf("----------------\n");
  nodo* current = head;
  UnrollLinkList* list = split(head,k, cant);
  traversal(list);
  return 0;
}
