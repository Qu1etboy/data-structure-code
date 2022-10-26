#include <iostream>
#include <vector>
using namespace std;

typedef struct tree {
  int size;
  int total;
  string name;
  struct tree* parent;
  vector<struct tree*> childs;

} Tree;

Tree* createNode(string name, int size) {
  Tree* node = new Tree;
  node->size = size;
  node->total = size;
  node->name = name;
  node->parent = NULL;
  return node;
}

Tree* addEdge(Tree* parent, Tree* child) {
  child->parent = parent;
  parent->childs.push_back(child);
}

void postorder(Tree* root) {
  for (Tree* child : root->childs) {
    postorder(child);
    root->total += child->total;
  }

  cout << root->name << " " << root->total << "K" << endl;
}

int main() {

  Tree* root = createNode("/users/rt/courses/", 1);
  Tree* node1 = createNode("cs016/", 2);
  Tree* node2 = createNode("cs252/", 1);
  Tree* node3 = createNode("grades", 8);
  Tree* node4 = createNode("homeworks/", 1);
  Tree* node5 = createNode("programs/", 1);
  Tree* node6 = createNode("projects/", 1);
  Tree* node7 = createNode("grades", 3);
  Tree* node8 = createNode("hw1", 3);
  Tree* node9 = createNode("hw2", 2);
  Tree* node10 = createNode("hw3", 4);
  Tree* node11 = createNode("pr1", 57);
  Tree* node12 = createNode("pr2", 97);
  Tree* node13 = createNode("pr3", 74);
  Tree* node14 = createNode("papers/", 1);
  Tree* node15 = createNode("demos/", 1);
  Tree* node16 = createNode("buylow", 26);
  Tree* node17 = createNode("sellhigh", 55);
  Tree* node18 = createNode("market", 4786);

  addEdge(root, node1);
  addEdge(root, node2);
  addEdge(node1, node3);
  addEdge(node1, node4);
  addEdge(node1, node5);
  addEdge(node4, node8);
  addEdge(node4, node9);
  addEdge(node4, node10);
  addEdge(node5, node11);
  addEdge(node5, node12);
  addEdge(node5, node13);
  addEdge(node2, node6);
  addEdge(node2, node7);
  addEdge(node6, node14);
  addEdge(node6, node15);
  addEdge(node14, node16);
  addEdge(node14, node17);
  addEdge(node15, node18);
  
  postorder(root);


}