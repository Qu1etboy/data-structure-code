#include <iostream>
#include <vector>
using namespace std;

vector<int> *createGraph(int n) {
  // return array of n lists
  return new vector<int>[n];
}

void addEdge(vector<int> *adjList, int u, int v) {
  adjList[u].push_back(v);
}

void printGraph(vector<int> *adjList, int V) {
  for (int v = 0; v < V; v++) {
    cout << "[" << v << "] head ";
    for (int i = 0; i < adjList[v].size(); i++)
      cout << "-> " << adjList[v].at(i);
    cout << endl; 
  }
  cout << endl;
}

int main() {
  int n = 5;

  vector<int> *adjList = createGraph(n);

  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 3);
  addEdge(adjList, 1, 2);
  addEdge(adjList, 1, 4);
  addEdge(adjList, 2, 1);
  addEdge(adjList, 2, 4);
  addEdge(adjList, 4, 3);

  printGraph(adjList, n);
  return 0;
}