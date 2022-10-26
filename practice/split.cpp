#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string input) {
  // input += " ";
  vector<string> list;
  string o = "";

  // copy from internet (should not cause the timelimit)
  string space_delimiter = " ";
  size_t pos;

  for (auto x : input)
    {
        if (x == ' ')
        {
            cout << o << endl;
            list.push_back(o);
            o = "";
        }
        else {
            o = o + x;
        }
    }
    cout << o << endl;
    list.push_back(o);

  // while ((pos = input.find(space_delimiter)) != string::npos) {
  //     list.push_back(input.substr(0, pos));
  //     input.erase(0, pos + space_delimiter.length());
  // }
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
  string a = "abcdefghijklmnop tom good kkk";
  vector<string> list = split(a);

  for (string s : list) {
    cout << s << "~" << endl;
  }
}