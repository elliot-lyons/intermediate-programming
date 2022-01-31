#include "Grammar.h"
#include <iostream>
#include <fstream>

Grammar::Grammar(){}

// open the file, get its lines one-by-one, feeding these to Rule constructor
// and using to build up rules member
Grammar::Grammar(string fname) {
  ifstream file;
  file.open(fname);
  string line;

  while (getline(file, line))
  {
    Rule current = Rule(line);        // putting the rule into the rules vector
    rules.push_back(current);
  }
}

// go thru rules using each members show method
void Grammar::show() {
  for (int i = 0; i < rules.size(); i++)
  {
    Rule current = rules.at(i);
    current.show();
    current.show_mother();
    current.show_daughters();
  }
}
