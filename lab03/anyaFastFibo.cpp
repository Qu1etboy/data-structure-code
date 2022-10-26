#include <iostream>
using namespace std;

int main() {
  unsigned long long n, f1 = 0, f2 = 1, f3;
  cin >> n;

  if (n >= 1) 
    cout << f1 << endl;
  if (n >= 2)
    cout << f2 << endl;   

  for (int i = 2; i < n; i++) {
    f3 = f1 + f2;
    cout << f3 << endl;
    f1 = f2;
    f2 = f3;
  }
}