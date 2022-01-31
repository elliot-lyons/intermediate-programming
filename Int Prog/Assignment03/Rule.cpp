#include "Rule.h"
#include <iostream>

Rule::Rule() {}

// make the rule_as_string member be same as 'input'
Rule::Rule(string input)
{
  rule_as_string = input;
  mother = "";
  
  int length = 0;

  while (rule_as_string[length] != '>' && length < rule_as_string.length())
  {
      length++;
  }

  if (length < rule_as_string.length())
  {
      for (int i = 0; i < length - 3; i++)
      {
          mother = mother + rule_as_string[i];
      }

      int current;

      for (int j = length + 2; j < rule_as_string.length(); j = j + current)
      {
          current = 0;
          char x;
          string daught = "";

          for (x = rule_as_string[j + current]; (x != ',') && 
            (j + current < rule_as_string.length()); current++)
          {
              x = rule_as_string[j + current];
              if (x != ',')
              {
                daught  = daught + x;
              }
          }

          if (daught != "")
          {
              daugthers.push_back(daught);
          }
      }
    }

    else
    {
        mother = rule_as_string;                // if this code is accessed, it must mean that there are no daughters
    }
}

// show the the rule_as_string member
void Rule::show() {
  cout << "\n\nWhole rule: " << rule_as_string  << endl;
}

void Rule::show_mother()        // showing the mother rule
{
    cout << "\nMother: " << mother << endl;
}

void Rule::show_daughters()         // showing the daughter rules
{
    cout << "\n";
    int i = 0;
    
    if (daugthers.size() > 0)
    {
        while (i < daugthers.size())
        {
            cout << "Daughter(" << (i + 1) << "): " << daugthers.at(i) << endl;
            i++;
        }
    }

    cout << "\nNumbers of daughters: " << i << "\n\n---------------------------" << endl;
}
