/************* TranslationDictionary.cpp **********************/
#include <string>
#include <iostream>
#include <fstream>

#include "TranslationDictionary.h"

using namespace std;

Trans_Dict::Trans_Dict() {}

/*************************************************************************/
/* builds dictionary from file with translation pairs source/translation */
/* on single lines                                                       */
/*************************************************************************/
Trans_Dict::Trans_Dict(string file_name) {
  string line, translation, word;
  ifstream f;
  Transpair p;
  size_t trans_offset;


  f.open(file_name);
  if(f) {
    opened_ok = true;
  }
  else {
    opened_ok = false;
  }
    
  if(opened_ok) {

    while(f >> line) {
      trans_offset = line.find('/'); /* trans_offset is location of / */

      if(trans_offset == string::npos) {
	cout << "there was an entry with no /\n";
	continue;
      }
      else {
	word = line.substr(0,trans_offset); // up to / 
	translation = line.substr(trans_offset+1); // after / 
	// make transpair with word and translation
	p.french = word;
	p.english = translation;
	thewords.push_back(p); // add transpair to thewords
      }

    }
  }

}


/*****************************************************************/
/* looks up word in dictionary, returning true or false          */
/* setting 'trans' to contain the translation if found           */
/*****************************************************************/
bool Trans_Dict::lookup(string word, string& trans) {
  int i;
  for(i = 0; i < thewords.size(); i++)
  {
    if (thewords[i].french == word)
    {
      trans = thewords[i].english;
      return true;
    }
  }
  
  return false;
}

bool Trans_Dict::other_lookup(string word, string& trans)   // this is for looking up English words
{
  for (int i = 0; i < thewords.size(); i++)
  {
    if (thewords[i].english == word)
    {
      trans = thewords[i].french;
      return true;
    }
  }

  return false;
}

void Trans_Dict::update(string french, string english)
{
  bool found = false;
  Transpair x;

  for (int i = 0; i < thewords.size(); i++)
  {
    if (thewords[i].french == french)
    {
      thewords[i].english = english;
      found = true;
    }
  }

  if (!found)
  {
    x.french = french;
    x.english = english;
    thewords.push_back(x);
  }
}

void Trans_Dict::display()
{
  for (int i = 0; i < thewords.size(); i++)
  {
    cout <<"\nFrench = " << thewords.at(i).french << " English = " << thewords.at(i).english;
  }
}

void Trans_Dict::export_to_file(string filename)
{
  ofstream myfile;

  myfile.open(filename);

  for (int i = 0; i < thewords.size(); i++)
  {
    myfile << thewords.at(i).french << "/" << thewords.at(i).english <<"\n";
  }

  myfile.close();
}






