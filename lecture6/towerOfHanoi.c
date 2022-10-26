#include <stdio.h>
#include <stdlib.h>

// create linkedlist
typedef struct node {
  int val;
  struct node *next;
} Node;

void insert(Node **head, int val) {
  Node *newNode = (Node*)malloc(sizeof(Node)), *tail;
  newNode->val = val;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
  } else {
    tail->next = newNode;
  }
  tail = newNode;
}

void delete(Node **head, int val) {
  Node *tmp = *head, *prev;
  if (tmp != NULL && tmp->val == val) {
    *head = tmp->next;
    return;
  }
  while (tmp != NULL && tmp->val != val) {
    prev = tmp;
    tmp = tmp->next;
  }
  if (tmp != NULL)
    prev->next = tmp->next;
    
}

void print(Node *ls) {
  Node *tmp = ls;
  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
}

Node *towerA;
Node *towerB;
Node *towerC;

void printTower() {
  printf("Tower A: ");
  print(towerA);
  printf("\nTower B: ");
  print(towerB);
  printf("\nTower C: ");
  print(towerC);
  printf("\n");
}

void move(int n, char from, char to) {
  if (from == 'A')
    delete(&towerA, n);
  if (from == 'B')
    delete(&towerB, n);
  if (from == 'C')
    delete(&towerC, n);
  if (to == 'A')
    insert(&towerA, n);
  if (to == 'B')
    insert(&towerB, n);
  if (to == 'C')
    insert(&towerC, n);
} 

void tower(int n, char from, char to, char aux) {
  if (n == 0) 
    return;
  
  tower(n - 1, from, aux, to);
  printf("Move disk %d from %c to %c\n", n, from, to);
  move(n, from, to);
  printTower();
  tower(n - 1, aux, to, from);
}

int main() {
  int n;
  scanf("%d", &n);

  // setup tower A
  for (int i = n; i > 0; i--) 
    insert(&towerA, i);

  printf("Start\n");
  printTower();

  tower(n, 'A', 'C', 'B');

}