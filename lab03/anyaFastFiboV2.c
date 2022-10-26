#include <stdio.h>

int main() {
  int n, f1 = 0, f2 = 1, f3;
  scanf("%d", &n);

  if (n >= 1) 
    printf("%d\n", f1);
  if (n >= 2)
    printf("%d\n", f2);

  for (int i = 2; i < n; i++) {
    f3 = f1 + f2;
    printf("%d\n", f3);
    f1 = f2;
    f2 = f3;
  }
}