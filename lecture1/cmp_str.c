#include <stdio.h>

int main() {
  char s1[255];
  char s2[255];

  scanf("%255s %255s", s1, s2);
  int i = 0, len_s1 = 0, len_s2 = 0;

  while (s1[len_s1] != '\0') {
    len_s1++;
  }
  while (s2[len_s2] != '\0') {
    len_s2++;
  }

  // find first character that are not equal
  while (s1[i] != s2[i] && s1[i] != '\0' && s2[i] != '\0') {
    i++;
  }
  i--;
  if (s1[i] < s2[i]) {
    printf("%s is less than %s", s1, s2);
  } else if (s1[i] > s2[i]) {
    printf("%s is greater than %s", s1, s2);
  } else {
    // if ascii value is equal check length
    if (len_s1 < len_s2) {
      printf("%s is less than %s", s1, s2);
    } else if (len_s1 > len_s2){
      printf("%s is greater than %s", s1, s2);
    } else {
      printf("%s is equal %s", s1, s2);
    }
  }
}