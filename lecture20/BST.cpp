#include <iostream>
#include <map>
using namespace std;

typedef struct node {
  int key;
  struct node* parent;
  struct node* left;
  struct node* right;

} Node;

// create a node with key
Node* createNode(int key) {
  Node* node = new struct node;
  node->key = key;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;

  return node; 
}

// insert a node with binary search tree property
// go left if node.key <= parent.key
// go right if node.key > parent.key
void insertNode(Node* root, Node* node) {
  Node* y = NULL; // prev
  Node* x = root;

  // loop through node in tree to find a position to put node into
  while (x != NULL) {
    y = x;
    if (node->key <= x->key) 
      x = x->left;
    else 
      x = x->right;
  }

  node->parent = y;

  if (y != NULL) {
    if (node->key <= y->key) 
      y->left = node;
    else 
      y->right = node;
  }

}

Node* minimum(Node* node) {
  Node* curr = node;
  Node* prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr->left;
  }
  return prev;
}

// u -> removing node
// v -> child of u
void transplant(Node* u, Node* v) {
  if (u->parent != NULL) {
    if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
  }

  if (v != NULL) {
    v->parent = u->parent;
  }
}

void deleteNode(Node* z) {
  if (z->left == NULL) {
    transplant(z, z->right);
  } else {
    if (z->right == NULL) {
      transplant(z, z->left);
    } else {
      // z have left and right child
      // find succssor of z which is somewhere in z right subtree
      Node* y = minimum(z->right);
      // if y is a child of z then no need to replace
      if (y->parent != z) {
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
      // replace z with y(successor of z)
      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;

    }
  }
}

bool isRoot(Node* node) {
  return node->parent == NULL;
}

// if insert correctly an order should be in sorted ascending order
void inorder(Node* root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }
}



int main() {
  // a node to insert
  int a[] = {3, 2, 8, 1, 5, 11, 4, 7, 10, 12, 6, 9};
  
  map<int, Node*> tree;

  // let first node be a root node
  Node* root = createNode(a[0]); 
  tree[a[0]] = root;


  for (int i = 1; i < sizeof(a) / sizeof(int); i++) {
    tree[a[i]] = createNode(a[i]);
    insertNode(root, tree[a[i]]);
  } 

  inorder(root);  

  cout << endl;
  deleteNode(tree[8]);
  deleteNode(tree[6]);
  deleteNode(tree[3]);
  deleteNode(tree[4]);
  // cout << (tree[4]->left->key) << " " << (tree[4]->right->key) << " " << isRoot(tree[4]) << endl;
  inorder(tree[5]);

  cout << endl;
  // cout << (isRoot(tree[12]) ? "YES" : "NO") << endl;
}