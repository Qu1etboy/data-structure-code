#include <stdio.h>

// program to transpose matrix
int main() {
  int m[4][5], tm[5][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      tm[i][j] = m[j][i];
    }
  }
  printf("/////////\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", tm[i][j]);
    }
    printf("\n");
  }

}