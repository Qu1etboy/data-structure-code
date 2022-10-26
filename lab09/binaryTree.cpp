#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef struct tree {
  string name;
  struct tree *left;
  struct tree *right;
} Tree;

// ok
Tree* createNode(string name) {
  Tree *node = new Tree;
  node->name = name;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// ok
void addChild(Tree* parent, Tree* child, string relationship) {
  if (relationship == "bad") {
    parent->left = child;
  } else {
    parent->right = child;
  }
}

int leftLeaf, rightLeaf;

// ok
void dfs(Tree* root, bool isLeft) {

  // found leaf node
  if (root->left == NULL && root->right == NULL) {
    if (isLeft == true) {
      leftLeaf++;  
      return;
    } else {
      rightLeaf++;
      return;
    }
  }

  if (root->left != NULL)
    dfs(root->left, true);
  if (root->right != NULL)
    dfs(root->right, false);
}

// ok
vector<string> split(string input) {
  input += " ";
  vector<string> list;
  string o = "";

  for (auto x : input) {
    if (x == ' ') {
      list.push_back(o);
      o = "";
    }
    else {
      o = o + x;
    }
  }

  // copy from internet (should not cause the timelimit)
  // string space_delimiter = " ";
  // size_t pos;
  // while ((pos = input.find(space_delimiter)) != string::npos) {
  //     list.push_back(input.substr(0, pos));
  //     input.erase(0, pos + space_delimiter.length());
  // }

  // my own implementation of spliting string by space
  // for (int i = 0, k = 0, l = 0; i < (int) input.size(); i++) {
  //   l++;
  //   if (i == (int) input.size() - 1) {
  //     list.push_back(input.substr(k, l));
  //     break;
  //   }
  //   if (input[i] == ' ') {
  //     list.push_back(input.substr(k, l-1));
  //     k = i + 1;
  //     l = 0;
  //   }
  // }
  return list;
}

int main() {
  map<string, Tree*> node;
  string rootName;
  getline(cin, rootName);
  node[rootName] = createNode(rootName);
  string input;

  // ok
  while (true) {
    getline(cin, input);
    if (input == "Airi is the best") {
      break;
    }
    // ok
    vector<string> list = split(input);
    
    string name1 = list[0];

    // ok 
    if (!node.count(name1)) {
      cout << "<`_`?>" << endl;
      continue;
    }

    string name2 = list[1];
    string relationship = list[2];
    
    // cout << name1 << name2 << relationship << endl;

    node[name2] = createNode(name2);

    addChild(node[name1], node[name2], relationship);
  }
  
  // ok
  if (node[rootName]->left == NULL && node[rootName]->right == NULL) {
    cout << rootName << " has no friend" << endl;
    return 0;
  }

  // ok
  dfs(node[rootName], false);

  cout << "Left: " << leftLeaf << endl;
  cout << "Right: " << rightLeaf << endl;

  return 0;
}