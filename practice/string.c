#include <string.h>
#include <stdio.h>

/**
 * Practice string.h libary function for data structure class 
 */
int main() {
  char s1[100] = "Hello";
  char s2[100];

  // strcpy(s2, s1); // to, from
  // strncpy(s2, s1, 3); // to, from, length
  
  char s3[100] = " World";
  strcat(s1, s3); // s1 + s3 -> Hello World

  char t[10] = "A";
  char w[10] = "B";

  // printf("%d", (int) strcmp(t, w)); // compare t with w if t < w return -1; if t > w return 1; if t == w return 0

  char word[] = "CS231 Data Structure";
  printf("%d\n", (int) sizeof(word)); // 20 + 1
  printf("%d\n", (int) strlen(word)); // 20

  // printf("%s\n", s2);
  // printf("%s\n", s1);
  // printf("%d\n", (int) strlen(s1));

}