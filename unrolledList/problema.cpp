#include <iostream>
#include <vector>
    vector<nodo*> splitListToParts(ListNode* root, int k) {
        // Create a vector of ListNode pointers to store the k parts.
        vector<nodo*> parts(k, nullptr);

        // Calculate the length of the linked list.
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;

        // Calculate the minimum guaranteed part size (n) and the number of extra nodes (r).
        int n = len / k, r = len % k;

        // Initialize pointers to traverse the linked list.
        nodo* node = root, *prev = nullptr;

        // Loop through each part.
        for (int i = 0; node && i < k; i++, r--) {
            // Store the current node as the start of the current part.
            parts[i] = node;
            // Traverse n + 1 nodes if there are remaining extra nodes (r > 0).
            // Otherwise, traverse only n nodes.
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            // Disconnect the current part from the rest of the list by setting prev->next to nullptr.
            prev->next = nullptr;
        }

        // Return the array of k parts.
        return parts;
    }
typedef struct nodo
{
  int data;
  struct nodo* next;
} nodo;
void push(nodo** head, int x)
{
  nodo* newNodo =(nodo*)malloc(sizeof(nodo));
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
int main()
{
  nodo* head = NULL;
  nodo** lastNode = &head;
  for (int i = 1; i < 15; i++)
  {
    push(lastNode, i);
    lastNode = &((*lastNode) -> next);
  }
  nodo* current = head;
  vector<nodo*> a =splitListToParts(head, 5);
  std::cout << a;
  return 0;
}
