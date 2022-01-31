#include "AMorse.h"
#include <iostream>
#include <fstream>

using namespace std;

Morse::Morse() {}


Morse::Morse(string fname)
{
    char letter;
    string the_morse, line;
    CodePair cp;
    ifstream j;

    j.open(fname);

    if (j)
    {
        while (getline(j, line))
        {
            the_morse = "";
            letter = line[0];

            for (int i = 2; i < line.length(); i++)
            {
                the_morse += line[i];
            }

            cp.plain = letter;
            cp.code = the_morse;

            code_table.push_back(cp);
        }
    }

    else
    {
        cout << "'" << fname << "' is an"
         << " invalid file name" << endl;
    }
}

void Morse::display()
{
    for (int i = 0; i < code_table.size(); i++)
    {
        cout << code_table.at(i).plain << " " << code_table.at(i).code << endl;
    }
}

string Morse::encode_a_letter(char c)
{
    for (int i = 0; i < code_table.size(); i++)
    {
        if (code_table.at(i).plain == c)
        {
            return code_table.at(i).code;
        }
    }

    return "****";
}

char Morse::decode_a_letter(string x)
{
    for (int i = 0; i < code_table.size(); i++)
    {
        if (x.compare(code_table.at(i).code) == 0)
        {
            return code_table.at(i).plain;
        }
    }

    return '*';
}

string Morse::encode_a_word(string w)
{
    string the_word = "";

    for (int i = 0; i < w.length(); i++)
    {
        the_word += encode_a_letter(w[i]);
        the_word += "   ";
    }

    return the_word;
}

string Morse::decode_a_word(string w)
{
    // vector <string> all_words = split (w, 7);
    // for (int j = 0; j < all_words.size(); j++)
    // {
    //      vector <string> the_word = split(all_words.at(j), 3);
    //      all code;   
    // }
    
    vector <string> the_word = {".-", "-...", "-...", ".-"};
    string result = "";

    for (int i = 0; i < the_word.size(); i++)
    {
        result += decode_a_letter(the_word.at(i));
    }

    return result;
}