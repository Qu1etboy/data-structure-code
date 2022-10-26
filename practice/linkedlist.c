#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} Node;

typedef struct list {
  Node *head;
  Node *tail;
} List;

void insertEnd(List *l, int val) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  if (l->head == NULL) {
    l->head = newNode;
  } else {
    l->tail->next = newNode;
  }
  l->tail = newNode;
}

void appendFront(List *l, int val) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  if (l->head == NULL) {
    l->head = newNode;
  } else {
    newNode->next = l->head;
    l->head = newNode;
  }

}


void deleteList(List *l, int val) {
  Node *prev = l->head, *curr = l->head;
  if (l->head == NULL) {
    return;
  }
  if (l->head->val == val) {
    l->head = curr->next;
    free(curr); 
  } else {
    while (curr != NULL && curr->val != val) {
      prev = curr;
      curr = curr->next;
    }
    if (curr != NULL) {
      prev->next = curr->next;
      free(curr);
    }
  }
}

void printList(List *l) {
  Node *tmp = l->head;
  for (; tmp != NULL; tmp = tmp->next) {
    printf("%d ", tmp->val);
  }
  printf("\n");
}

void initList(List *l) {
  l->head = NULL;
  l->tail = NULL;
}


int main() {
  List l;
  initList(&l);

  for (int i = 0; i < 5; i++) {
    appendFront(&l, i);
  }

  printList(&l);

  deleteList(&l, 0);

  printList(&l);
}