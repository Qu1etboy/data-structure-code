#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

typedef struct linked_list {
  int length; 
  Node *head;
  Node *tail;
} NumList;

Node *newNode() {
  Node *p;
  p = (Node*) malloc(sizeof(Node));
  p->next = NULL;
  return p;
}

void initList(NumList *n) {
  n->head = NULL;
  n->tail = NULL;
}

void printNumList(NumList L) {
  Node *pCurr = L.head;
  while (pCurr != NULL) {
    printf("Num: %d\n", pCurr->num);
    pCurr = pCurr->next;
  }
}

void insertEnd(NumList *s, Node *p) {
  if (s->head == NULL) {
    s->head = p;
  } else {
    s->tail->next = p;
  }
  s->tail = p;
}

int main() {
  NumList NL;
  initList(&NL);
  for (int i = 0; i < 3; ++i) {
    Node *N = newNode();
    N->num = i;
    insertEnd(&NL, N);
  }

  printNumList(NL);
  return 0;
}