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

int height;

void findHeight(Tree* root, int depth) {
  if (root->left == NULL && root->right == NULL) {
    height = max(height, depth);
  }
  
  if (root->left != NULL) 
    findHeight(root->left, depth + 1);
  if (root->right != NULL)
    findHeight(root->right, depth + 1);
}

void preorder(Tree* root) {  
  cout << root->key << " ";
  if (root->left != NULL) 
    preorder(root->left);
  if (root->right != NULL)
    preorder(root->right);
}

void postorder(Tree* root) {
  if (root->left != NULL) 
    postorder(root->left);
  if (root->right != NULL)
    postorder(root->right);
  cout << root->key << " ";
}

void inorder(Tree* root) {
  if (root->left != NULL) 
    inorder(root->left);
  cout << root->key << " ";
  if (root->right != NULL)
    inorder(root->right);
}

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "What is emptier, my heart or this tree?" << endl;
    return 0;
  }

  Tree* root = createNode(n);

  while (true) {
    cin >> n;
    if (n == 0) break;

    Tree* node = createNode(n);
    addNode(root, node);
  }
  findHeight(root, 0);
  cout << "Height: " << height << endl;
  cout << "Preorder: ";
  preorder(root);
  cout << "\nInorder: ";
  inorder(root);
  cout << "\nPostorder: ";
  postorder(root);
  cout << endl;
}
