#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct tree {
  string path;
  vector<struct tree*> childs;

} Tree;

void addNode(Tree* parent, Tree* child) {
  parent->childs.push_back(child);
}

Tree* createNode(string path) {
  Tree* node = (Tree*) malloc(sizeof(Tree));
  node->path = path;
  return node;
}

string absolutePath = "";

void dfs(Tree* root, string path, string dest) {

  if (root->path == dest) {
    absolutePath = path;
    return;
  }

  for (Tree* child : root->childs) {
    dfs(child, path + "/" + child->path, dest);
  }
}

int main() {
  string folder, file;
  map<string, Tree*> node;

  Tree *root = (Tree*) malloc(sizeof(Tree));
  root->path = "/";

  node["/"] = root;

  while (true) {
    cin >> folder;
    if (folder == "<`~`?>") {
      break;
    }
    cin >> file;

    // Tree *newNode = createNode(file);

    if (!node.count(file)) {
      node[file] = createNode(file);
    }

    if (!node.count(folder)) {
      node[folder] = createNode(folder);
    }

    addNode(node[folder], node[file]);

  }
  string dest;
  cin >> dest;
  // root directory
  if (dest == "/") {
    absolutePath = "/";
  } else {
    dfs(root, "", dest);
  }
  

  if (absolutePath != "") {
    cout << absolutePath << endl;
  } else {
    cout << "(╯°□°）╯︵ ┻━┻ - Not found, Alas!!!" << endl;
    cout << "┬─┬ /( ゜-゜/) - Calm down bro." << endl;
  }

  return 0;
}

/*

/ users
users ~
~ secret_dont_open
secret_dont_open I_already_warn_you
I_already_warn_you last_alert
last_alert DATA-651.avi
<`~`?>
DATA-651.avi

*/