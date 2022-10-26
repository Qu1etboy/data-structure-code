#include <stdio.h>

int a(int n, int v) {
  if (n == 1) {
    return v;
  }
  return a(n - 1, v + 3);
}

int main() {
  printf("%d", a(5, 2));
}