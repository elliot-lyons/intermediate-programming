#include "list.cpp"
#include <iostream>
#include <string>

using namespace std;
int main() {

  list l;
  string word;
  l.push("c");
  l.push("b");
  l.push("a");
  l.printlist();
  word = l.pop();
  l.push("b");
  cout << l.count("b") << endl;
  cout << l.count("a") << endl;
  cout << l.count("hrujhr") << endl;
  string bottom;
  bool x = l.bottom(bottom);
  cout << bottom << endl;
  l.printlist();
}