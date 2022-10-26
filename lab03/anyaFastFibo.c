#include <stdio.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);

  long long fib[n + 2];
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  for (int i = 0; i < n; i++) {
    printf("%lld\n", fib[i]);
  }

  return 0;
}