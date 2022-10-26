#include <stdio.h>

int main() {
  int n = 5;
  char grid[n+1][n+1];
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = n - 1, k = n - 1; j >= 0; j--) {
      if (grid[j][i] != '.') {
        if (grid[k][i] == '.') {
          grid[k--][i] = grid[j][i];
          grid[j][i] = '.';
        } else {
          k--;
        }
      }
    } 
  }
  printf("=========\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", grid[i]);
  }

}

/*
.....
..D..
AC...
..E.F
.B...
*/