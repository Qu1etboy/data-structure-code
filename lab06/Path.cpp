#include <iostream>
using namespace std;

int n, e;
int adj[10000][10000];
int from, to;
int color[10000];
bool found;

void dfs(int u) {
  if (u == to) {
    found = true;
    return;
  }
  if (color[u] == 1 || color[u] == 2) {
    return;
  }
  color[u] = 1;
  for (int v = 0; v < n; v++) {
    if (adj[u][v]) {
      dfs(v);
    }
  }
  color[u] = 2;
  return;
}

int main() {
  cin >> n;
  cin >> e;

  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
  }

  cin >> from >> to;

  dfs(from);

  cout << (found ? "True" : "False") << endl;

  return 0;
}