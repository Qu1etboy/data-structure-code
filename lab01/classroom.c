#include <stdio.h>
#include <math.h>

int main() {
  int t;
  scanf("%d", &t);
  if (t < 1) {
    printf("Error");
    return 0;
  } 
  if (t > 40) {
    printf("Error!");
    return 0;
  } 
  int n, k = 0, nt = 0, l = 0;
  scanf("%d", &n);
  char take[10][6] = {};

  // set take to 'X'
  while (1) {
    int out = 0;
    for (int j = 0; j < 6; j++) {
      if (nt >= t) {
        out = 1;
        break;
      }
      take[l][j] = 'X';
      nt++;
    }
    l++;
    if (out) {
      break;
    }
  }

  // set take table to be 'S'
  while (k < n) {
    int r, c;
    scanf("%d %d", &r, &c);
    if (r < 1 || c < 1 || r > 7 || c > 6 || take[r-1][c-1] != 'X') {
      printf("%d %d Out of range!\n", r, c);
      continue;
    }
    take[r-1][c-1] = 'S';
    k++;
  }

  // print the table
  l = 0, nt = 0;
  while (1) {
    int out = 0;
    for (int j = 0; j < 6; j++) {
      if (nt >= t) {
        out = 1;
        break;
      }
      printf("%c ", take[l][j]);
      nt++;
    }
    printf("\n");
    l++;
    if (out) {
      break;
    }
  }

  return 0;
}