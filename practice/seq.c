#include <stdio.h>

int a(int m) {
  if (m == 0) return 0;
  if (m == 1) return 1;
  if (m % 2 == 0) {
    return a(m/2);
  }
  return a((m-1)/2) + a((m-1)/2 + 1);
}

int main() {
  for (int i = 0; i <= 15; i++) {
    printf("%d ", a(i));
  }
}
