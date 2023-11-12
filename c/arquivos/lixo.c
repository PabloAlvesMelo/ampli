#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
  if(new_node != NULL) {
  new_node->data  = new_data;
  new_node->next = (*head_ref);
  (*head_ref)    = new_node;
  } else {
    printf("Falha na alocação de memória. Não foi possível inserir o elemento.\n");
    return;
  }
}

void printList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {
  struct Node* head = NULL;
  insertAtBeginning(&head, 7);
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 2);
  
  printf("Lista ligada criada é: ");
  printList(head);
  
  return 0;
}
