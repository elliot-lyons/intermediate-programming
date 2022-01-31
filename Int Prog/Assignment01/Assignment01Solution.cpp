#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

bool is_vowel(char c);
bool is_cons(char c);

int main() {
  ifstream thefile;
  thefile.open("afile_from_bodmer");

  cout << "elim which?: enter 1 for vowels or 2 for cons\n";
  int choice;
  cin >> choice;

  string s;
  char current_char;
  
  while(getline(thefile,s))                                // puts whole next line into s
  { 
    int n = s.length();
    char char_array[n+1];                                  // this is creating a character array 'char_array', the same length as the String 's'
    strcpy(char_array, s.c_str());                         // this copies the String into a character array. The c_str() function pointing the strcpy() to the null-terminated String 's'

    for (int i = 0; i < n; i++)
    {
      current_char = char_array[i];

      if (choice == 1 && is_vowel(current_char))
      {
	char_array[i] = '*';                               // replacing the vowel with '*' should it need to
      }

      else if (choice == 2 && is_cons(current_char))	
      {
        char_array[i] = '*';                               // replacing the consonant with '*' should it need to
      }

      cout << char_array[i];                               // outputting the adjusted character  
    }

  }

  cout << "\n";

  return 0;

}
