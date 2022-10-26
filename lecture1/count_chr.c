#include <stdio.h>

int main() {
  int i = 0;
  char s[255];
  fgets(s, 255, stdin);
  while (s[i] != '\0') {
    i++;
  }
  printf("%d", i-1); // -1 don't count '\0'

}

