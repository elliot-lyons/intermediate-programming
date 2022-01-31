#include <string>
#include <vector>

using namespace std;

class Rule 
{
 public:
  Rule();
  Rule(string input);

  string rule_as_string;
  string mother;
  vector <string> daugthers;
  
  void show();
  void show_mother();
  void show_daughters();
};