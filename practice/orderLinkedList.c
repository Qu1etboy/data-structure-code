#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct linked_list {
  Node *head;
} List;

void initList(List *list) {
  list->head = NULL;
}

void insertOrderedList(List *list, int data) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else if (newNode->data <= list->head->data) {
    newNode->next = list->head;
    list->head = newNode;
  } else {
    Node *curr = list->head;
    while (curr->next != NULL && curr->next->data < newNode->data) {
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
}

int main() {
  List list;
  initList(&list);
  int size;
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    int data;
    scanf("%d", &data);
    insertOrderedList(&list, data);
  }

  // print list
  Node *tmp = list.head;
  while (tmp != NULL) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }

  return 0;
}