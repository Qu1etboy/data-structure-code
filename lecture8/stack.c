#include <stdio.h>

int validParen(char paren[]) {
  char stack[100];
  int top = -1;

  for (int i = 0; paren[i] != '\0'; i++) {
    if (top == -1 || paren[i] == '(' || paren[i] == '{' || paren[i] == '[') {
      top++;
      stack[top] = paren[i];
    } 
    else if ((stack[top] == '(' && paren[i] == ')') || 
             (stack[top] == '{' && paren[i] == '}') ||
             (stack[top] == '[' && paren[i] == ']')) {
      top--;
    }
    else {
      return 0;
    }
  }
  return top == -1;
}

int main() {
  char stack[100];
  int top = -1;

  char paren[100];
  scanf("%s", paren);

  printf("%s\n", validParen(paren) ? "YES" : "NO");

  
}