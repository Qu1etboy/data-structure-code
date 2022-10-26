#include <iostream>
#include <map>
using namespace std;

typedef struct tree {
  int val;
  struct tree* parent;
  struct tree* left;
  struct tree* right;
} Tree;

Tree* createNode(int val) {
  Tree* node = new Tree;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

bool addEdge(Tree* parent, Tree* child, string side) {
  if (side == "L") {
    if (parent->left != NULL)
      return false;
    parent->left = child;
  } else {
    if (parent->right != NULL)
      return false;
    parent->right = child;
  }
  child->parent = parent;
  return true;
}

int main() {
  int root, p, c;
  string d;
  cin >> root;
  bool valid = true;
  map<int,Tree*> node;

  node[root] = createNode(root);

  int count = 0;
  while (true) {
    cin >> p >> c >> d;

    if (p == 0 && c == 0 && d == "end") {
      break;
    }
    if (node[c] != NULL) {
      cout << "Not what I am looking for, I am afraid." << endl;
      return 0;
    }

    if (d == "R" && p >= c) {
      valid = false;
      continue;
    }
    if (d == "L" && p < c) {
      valid = false;
      continue;
    }

    node[c] = createNode(c);

    if (!addEdge(node[p], node[c], d)) {
      cout << "Not what I am looking for, I am afraid." << endl;
      return 0;
    }

    count++;
  }

  if (count == 0) {
    cout << "This tree is lonely, give them a hug." << endl;
  }
  else if (valid) {
    cout << "A binary search tree, this is." << endl;
  } else {
    cout << "This tree is illegal." << endl;
  }

  return 0;
}