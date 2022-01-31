#include "Rule.h"
#include <vector>

using namespace std;

class Grammar {
 public:
  Grammar();
  Grammar(string filename);
  vector<Rule> rules;
  Rule current;
  void show();

};
