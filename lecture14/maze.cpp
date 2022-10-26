#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
  int V;
  vector<int> *adj;
public:
  Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool BFSCanVisit(int from, int to) {
    queue<int> queue;
    queue.push(from);
    bool visited[V];
    for (int i = 0; i < V; i++) 
      visited[i] = false;

    bool found = false;

    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      
      if (u == to) {
        found = true;
      }
      for (auto v : adj[u]) {
        if (!visited[v]) {
          visited[v] = true;
          queue.push(v);
        }
      }
    }

    return found;
  }
};

int main() {
  Graph g(19);

  g.addEdge(0, 1);
  g.addEdge(1, 6);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(2, 5);
  g.addEdge(6, 7);
  g.addEdge(6, 8);
  g.addEdge(8, 9);
  g.addEdge(8, 10);
  g.addEdge(8, 11);
  g.addEdge(11, 12);
  g.addEdge(11, 13);
  g.addEdge(13, 14);
  g.addEdge(13, 15);
  g.addEdge(15, 16);
  g.addEdge(15, 17);
  g.addEdge(15, 18);

  cout << (g.BFSCanVisit(0, 18) ? "YES" : "NO") << endl;
}