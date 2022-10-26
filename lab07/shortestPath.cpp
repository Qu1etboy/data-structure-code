#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n, e;
  cin >> n >> e;
  vector<int> adj[n];
  bool visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = false;

  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int start, end;
  cin >> start >> end;

  int path[n];
  bool found = false;
  priority_queue<int, vector<int>, greater<int> > queue;
  queue.push(start);

  while (!queue.empty()) {
    int u = queue.top();
    queue.pop();

    for (int i = 0; i < adj[u].size(); i++) {
      if (!visited[adj[u][i]]) {
        visited[adj[u][i]] = true;
        queue.push(adj[u][i]);
        path[adj[u][i]] = u;

        if (adj[u][i] == end) {
          found = true;
          break;
        }
      }
    }

    if (found)
      break;
  }
  
  if (!found) {
    cout << "404: Path not found :(" << endl;
    return 0;
  }

  vector<int> shortestPath;
  int dest = end;
  shortestPath.push_back(dest);
  while (path[dest] != start) {
    shortestPath.push_back(path[dest]);
    dest = path[dest];
  }

  cout << "Shortest Distance: " << shortestPath.size() << endl;;
  cout << "Path = " << start << " > ";
  for (int i = shortestPath.size() - 1; i > 0; i--) {
    cout << shortestPath[i] << " > ";
  }
  cout << end << " :)" << endl;
}
