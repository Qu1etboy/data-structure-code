#include <stdio.h>

int main() {
  int arr[5][3];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 3; j++) 
      scanf("%d", &arr[i][j]);

  for (int i = 0; i < 5; i++) {
    int sumRow = 0;
    for (int j = 0; j < 3; j++) {
      sumRow += arr[i][j];
    }
    printf("sum of row %d is %d\n", i, sumRow);
  }

  for (int i = 0; i < 3; i++) {
    int sumCol = 0;
    for (int j = 0; j < 5; j++) {
      sumCol += arr[j][i];
    }
    printf("sum of col %d is %d\n", i, sumCol);
  }

  return 0;
}