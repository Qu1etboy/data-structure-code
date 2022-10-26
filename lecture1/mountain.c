#include <stdio.h>

int main() {
  int n, maxH = 0, maxW = 0;
  scanf("%d", &n);
  int h[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    if (h[i] > maxH) {
      maxH = h[i];
    }
    maxW += h[i]*2;
  }
  char mountains[maxH][maxW];
  for (int i = 0; i < maxH; i++) {
    for (int j = 0; j < maxW; j++) {
      mountains[i][j] = ' ';
    }
  }
  int l = 0, r = h[0]*2 - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < h[i]; j++) {
      mountains[maxH - j - 1][l + j] = '/';
      mountains[maxH - j - 1][r - j] = '\\';
    }
    l += h[i]*2;
    if (i < maxH)
      r += h[i+1]*2;
  }

  for (int i = 0; i < maxH; i++) {
    for (int j = 0; j < maxW; j++) {
      printf("%c", mountains[i][j]);
    }
    printf("\n");
  }
}


/*
    /\
   /  \  /\
/\/    \/  \
012345678901

1 3 2

*/