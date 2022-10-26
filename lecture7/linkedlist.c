#include <stdio.h>
#include <stdlib.h>

struct Node {
  int num;
  struct Node *next;
};

int main() {
  struct Node *first = NULL;
  struct Node *second = NULL;
  struct Node *last = NULL;

  first = (struct Node*)malloc(sizeof(struct Node)); 
  second = (struct Node*)malloc(sizeof(struct Node));
  last = (struct Node*)malloc(sizeof(struct Node));

  first->num = 1;
  first->next = second;

  second->num = 3;
  second->next = last;

  last->num = 5;
  last->next = NULL;

  return 0;
}