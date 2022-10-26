#include <iostream>
using namespace std;

typedef struct tree {
  int key;
  struct tree* parent;
  struct tree* left;
  struct tree* right;
} Tree;

Tree* createNode(int k) {
  Tree* node = new Tree;
  node->key = k;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void addNode(Tree* root, Tree* node) {
  Tree* tmp = root;
  Tree* y = NULL;
  while (tmp != NULL) {
    y = tmp;
    if (node->key <= tmp->key) {
      tmp = tmp->left;
    } else {
      tmp = tmp->right;
    }
  }

  node->parent = y;
  if (y != NULL) {
    if (node->key <= y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
  }
  
}

int isAVL(Tree* root) {
  if (root == NULL) {
    return 0;
  }
  int leftSubtree = isAVL(root->left);
  if (leftSubtree == -1) return -1;

  int rightSubtree = isAVL(root->right);
  if (rightSubtree == -1) return -1;

  if (abs(leftSubtree - rightSubtree) > 1) return -1;

  return max(leftSubtree, rightSubtree) + 1;

}

int main() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << "empty tree" << endl;
    return 0;
  }

  Tree* root = createNode(n);

  while (true) {
    cin >> n;
    if (n == 0) break;

    Tree* node = createNode(n);
    addNode(root, node);
  }

  int valid = isAVL(root);

  if (valid != -1) {
    cout << "This tree has AVL property" << endl;
  } else {
    cout << "This tree doesn't have AVL property" << endl;
  }
}