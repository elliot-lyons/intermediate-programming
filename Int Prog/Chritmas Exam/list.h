#include <iostream>
//#include <stdlib.h>
#include <string>

using namespace std;

class list_item {
 public:
  string info;
  list_item *next;
};


class list {

 public:
  list(void);
  ~list(void);

  void push(string i);
  string pop(void);
  void printlist(void);
  void other_print();
  int size;
  void empty(void);
  int count (string x);
  bool bottom(string& s);

 private:
  list_item *thelist;
  void printlist(list_item *list);
  void other_print(list_item* list);
};



