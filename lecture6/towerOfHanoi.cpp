#include <iostream>
#include <vector>
using namespace std;

vector<int> towerA;
vector<int> towerB;
vector<int> towerC;

void printTower() {
  cout << "Tower A: ";
  for (int i : towerA)
    cout << i << " ";
  cout << "\nTower B: ";
  for (int i : towerB)
    cout << i << " ";
  cout << "\nTower C: ";
  for (int i : towerC)
    cout << i << " ";
  cout << "\n";
}

void move(int n, char from, char to) {
  if (from == 'A')
    towerA.pop_back();
  if (from == 'B')
    towerB.pop_back();
  if (from == 'C')
    towerC.pop_back();
  if (to == 'A')
    towerA.push_back(n);
  if (to == 'B')
    towerB.push_back(n);
  if (to == 'C')
    towerC.push_back(n);
} 

void tower(int n, char from, char to, char aux) {
  if (n == 0) 
    return;
  
  tower(n - 1, from, aux, to);
  cout << "Move disk " << n << " from " << from << " to " << to << endl;
  move(n, from, to);
  printTower();
  tower(n - 1, aux, to, from);
}

int main() {
  int n;
  cin >> n;

  for (int i = n; i > 0; i--) 
    towerA.push_back(i);

  cout << "Start" << endl;
  printTower();

  tower(n, 'A', 'C', 'B');

}
