#include <stdio.h>

int main() {
  int a = 10;
  int *ptr = &a;

  printf("a = %d\n", a);
  printf("*ptr = %d\n", *ptr);
  printf("*&ptr = %p\n", *&ptr);
  printf("&*ptr = %p\n", &*ptr);
}