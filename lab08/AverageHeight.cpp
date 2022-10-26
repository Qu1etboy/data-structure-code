#include <iostream>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

typedef struct tree {
  int val;
  struct tree* parent;
  vector<struct tree*> childs;

} Tree;

void addNode(Tree *parent, Tree *child) {
  child->parent = parent;
  parent->childs.push_back(child);
}

Tree* createNode(int val) {
  Tree *node = (Tree*) malloc(sizeof(Tree));
  node->parent = NULL;
  node->val = val;

  return node;
}

double total;
double num_leaf;

void dfs(Tree* root, int val) {
  // found leaf node
  if (root->childs.size() == 0) {
    // cout << val << endl;
    total += val;
    num_leaf += 1;
    return;
  }

  for (Tree* child : root->childs) {
    dfs(child, val + child->val);
  }

}

int main() {
  string start, end;
  int n, w;
  cin >> n;
  map<string, Tree*> node;
  Tree *root = (Tree*) malloc(sizeof(Tree));
  root->val = 0;
  root->parent = NULL;

  node["0"] = root;

  for (int i = 0; i < n; i++) {
    cin >> start >> end >> w;
    Tree *newNode = createNode(w);
    node[end] = newNode;

    addNode(node[start], node[end]);
  }

  dfs(root, root->val);

  printf("%.2f\n", total / num_leaf);

}