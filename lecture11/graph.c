#include <stdio.h>
#include <stdlib.h>

int** createGraph(int n) {
  int **adj = calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++)
    adj[i] = calloc(n, sizeof(int)); 

  return adj;
}

void addEdge(int **adj, int u, int v) {
  adj[u][v] = 1;
}

void printGraph(int **adj, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n = 5;
  int **adj = createGraph(n);

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);

  printGraph(adj, n);

  return 0;
}