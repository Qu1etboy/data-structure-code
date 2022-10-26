#include <stdio.h>

int main() {
  char s1[255];
  char s2[127];
  scanf("%255s %127s", s1, s2);
  int i = 0, j = 0;

  while (s1[i] != '\0') {
    i++;
  } 
  while (s2[j] != '\0') {
    s1[i] = s2[j];
    i++;
    j++;
  }
  s1[i] = '\0';
  printf("Result after concatenate is %s with length of %d", s1, i);
}