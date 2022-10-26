#include <iostream>
using namespace std;

int n, e;
int adj[10000][10000];
int color[10000];
bool isCycle;

void dfs(int u) {
  if (color[u] == 1) {
    isCycle = 1;
    return;
  }
  if (color[u] == 2) {
    return;
  }
  color[u] = 1;
  for (int v = 0; v < n; v++) {
    if (adj[u][v])
      dfs(v);
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

  for (int u = 0; u < n; u++) {
    if (color[u] == 0) {
      dfs(u);
    }
  }
  if (isCycle) {
    cout << "Graph contains cycle" << endl;
  } else {
    cout << "Graph doesn't contain cycle" << endl;
  }

  return 0;

}