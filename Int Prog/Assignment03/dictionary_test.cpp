/*********************************/
/* tests the Trans_Dict class    */
/*********************************/
#include <iostream>
#include <fstream>
#include "TranslationDictionary.h"
#include <stdlib.h>

using namespace std;

void tester_function(Trans_Dict& d, string name, vector<string> words, string language);


int main() {
    Trans_Dict d1("translist.txt");  
    Trans_Dict d2("translist2.txt");  

    if(!d1.opened_ok) {
      cerr << "dictionary to translist did not open ok\n";
      exit(0);
    }

    if(!d2.opened_ok) {
      cerr << "dictionary to translist2 did not open ok\n";
      exit(0);
    }

    vector <string> fr_words;
    vector <string> en_words;

    string updated_translist = "updated_translist.txt";
    string updated_translist2 = "updated_translist2.txt";

    fr_words = {"soulier", "jupe", "chien"};
    tester_function(d1, "translist", fr_words, "french");
    fr_words = {"chien", "oiseau", "soulier"};
    tester_function(d2, "translist2", fr_words, "french");

    cout << "\n";

    en_words = {"shoe", "skirt", "dog"};
    tester_function(d1, "translist", en_words, "english");
    en_words = {"dog", "bird", "shoe"};
    tester_function(d2, "translist2", en_words, "english");

    d1.update("soulier", "sock");             // overwriting thewords.english for "soulier" to "sock"
    d1.update("sauteur", "jumper");           // adding a new set of words to vector
    cout << "\n------------------\n\n" << "After updating:" << endl;
    d1.display();                             // displaying new changes, the translist document is not changed

    cout << "\n";
    d2.update("chien", "cat");                // overwriting thewords.english fir "chien" to cat
    d2.update("poisson", "fish");             // adding a new set of words to vector
    cout << "\n------------------\n\n" << "After updating:" << endl;
    d2.display();                             // displaying new changes, the translist document is not changed

    d1.export_to_file(updated_translist);     // this will write the original document with the changes made to an external doc
    d2.export_to_file(updated_translist2);    // this will write the original document with the changes made to an external doc
}

void tester_function(Trans_Dict& d, string name, vector<string> words, string language)   // language represents what language we are working in (French / English)
{         // this is necessary to know so we can choose the right look_up function
  string trans;
  bool found;
 
  for(unsigned int i = 0; i < words.size(); i++)
  {
   if((language == "french") ?  d.lookup(words[i], trans) : d.other_lookup(words[i], trans))
    {
      cout << name << " trans of " << words[i] << " is " << trans << endl;
    }

    else
    {
      cout << "no " << name << " trans of " << words[i] << endl;
    }
  }
}