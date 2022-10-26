#include <iostream>
using namespace std;

void remove(string foods[], int n, int target) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i != target) {
      foods[j++] = foods[i];
    }
  }
}

void show(string foods[], int n) {
  cout << "<< Menu >>" << endl;
  for (int i = 0; i < n; i++) {
    cout << i+1 << ". " << foods[i] << endl;
  }
}

int main() {
  string foods[100], food;
  string op = "";
  int i = 0, target;

  while (op != "exit") {
    cin >> op;
    if (op == "add") {
      cin >> food;
      foods[i] = food;
      i++;
    } 
    else if (op == "del") {
      cin >> target;
      if (target > 0 && target <= i) {
        remove(foods, i, target - 1);
        i--;
      }
    }
    else {
      show(foods, i);
    }
  }

  return 0;
}