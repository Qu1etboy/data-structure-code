#include <stdio.h>

int ack(int m, int n) {
  if (m > 0 && n == 0)
    return ack(m - 1, 1);
  if (m > 0 && n > 0)
    return ack(m - 1, ack(m, n - 1));
  return n + 1;
}

int main() {
  printf("%d", ack(2, 1));
}