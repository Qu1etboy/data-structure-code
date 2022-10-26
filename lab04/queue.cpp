#include <iostream>
using namespace std;

int main() {
  string queue[10000], op;
  int front = -1, rear = -1;
  do {
    cin >> op;

    if (op == "enqueue") {
      rear++;
      if (front == -1) front++;
      cin >> queue[rear];
    } else if (op == "dequeue") {
      if (front != -1 && rear != -1 && front != rear + 1) {
        cout << queue[front] << endl;
        front++;
      }
    } else if (op == "peek") {
      if (front != -1 && rear != -1 && front != rear + 1)
        cout << queue[front] << endl;;
    } else if (op == "empty?") {
      if (front == -1 || rear == -1 || front == rear + 1) {
        cout << "EmPTy" << endl;
      } else {
        cout << "nOT EmpTY" << endl;
      }
    }

  } while (op != "exit");

  return 0;
}