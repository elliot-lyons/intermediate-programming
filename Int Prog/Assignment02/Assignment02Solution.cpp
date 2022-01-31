#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

bool is_an_email(string s);

int main() {

  string filename;
  cout << "which file\n";
  cin >> filename;
  
  ifstream f;
  f.open(filename);
  if(!f) { cout << "could not open\n"; return 0; }

  // // block to test is_an_email
  // // you might want to un-comment this to test your function before
  // // proceeding

  /*vector<string> emails = {"amy@blah", "@blah", "blah@"};

  for(int i=0; i < emails.size(); i++)
    {
      cout << emails[i] << ": ";

      if(is_an_email(emails[i]))
	{
	  cout << "yep\n";
	}
      
      else
	{
	  cout << "nope\n";
	}
    }
  */

  vector<string> wholeFile;
  string line;
  string  word;
  stringstream copy;
  vector<string> theEmails;
  bool secret = false;

  while(getline(f, line, '\n'))
    { 
      if (line.size() > 0)
	{
	  copy <<  line;                         // making a copy of the line so we can split it further into words

	  while (getline(copy, word, ' '))
	    {
	      wholeFile.push_back(word);        // pushing the words onto a vector

	      if (line.find("TOP-SECRET") != string::npos)
		{
		  secret = true;
		}

	      else if (is_an_email(word))
		{
		  theEmails.push_back(word);
		}
	    }
	  copy.clear();
	}
    }

      if (secret)
	{
	  for (int i = 0; i < theEmails.size(); i++)
	    {
	      cout << theEmails[i] << "\n";
	    }
	}
  
  return 1;
   }

  // ADD FURTHER CODE HERE
  // make a vector of all the file's contents and then process that
  
  // DESIRED BEHAVIOUR: if run on top_secret_file should see
  
  // lisa@simpsons.sit.com
  // joey@friends.sit.com
  // homer@simpsons.sit.com
  // marge@simpsons.sit.com
  // bart@simpsons.sit.com
  // maggie@simpsons.sit.com
  // rachel@friends.sit.com
  // ross@friends.sit.com
  // chandler@friends.sit.com
  // monica@friends.sit.com


  

// COMPLETE THE FUNCTION is_an_email(string s) 
// it should check that
// s contains @ somewhere,
//  but not right at start
//  and not right at end
// ie.
//  amy@blah -> true
//  @blah    -> false
//  blah@    -> false
bool is_an_email(string s) {

  size_t found = s.find('@');

  if (found != string::npos && found > 0 && found < s.length() - 1)
    {
      return true;
    }

  return false;
  
}
