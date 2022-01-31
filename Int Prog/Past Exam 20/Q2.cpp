#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime> 


using namespace std;
void put_in_dictionary(vector <string>& dictionary, string fname);
void word_game(vector <string> dictionary);

int main()
{
    vector <string> dictionary;
    string fname = "dictionary.txt";

    put_in_dictionary(dictionary, fname);
    word_game(dictionary);

    return 1;
}

void put_in_dictionary(vector <string>& dictionary, string fname)
{
    string line;
    ifstream f;

    f.open(fname);

    if (f)
    {
        while (getline(f, line))
        {

            dictionary.push_back(line);
        }
    }

    else
    {
        cout << "Problem opening file" << endl;
    }
}

void word_game(vector <string> dictionary)
{
    bool finished = false;
    bool invalid = false;
    bool incorrect = false;
    string line;
    int pos;
    char letter;
    string source;
    string target;

    int rand_one;
    int rand_two;

    // bool first = false;

    // while (!first)
    // {
    //     srand(time(0));
    //     rand_one = rand() + 154472;

    //     if (rand_one < dictionary.size())
    //     {
    //         source = dictionary.at(rand_one);
    //         first = true;
    //     }
    // }

    // bool second = false;

    // while (!second)
    // {
    //     rand_two = rand() + 154472;

    //     if (rand_two < dictionary.size() && rand_one != rand_two)
    //     {
    //         target = dictionary.at(rand_two);

    //         if (target.length() == source.length())
    //         {
    //             second = true;
    //         }
    //     }
    // }

    source = "pint";
    target = "plots";

    cout << "Source word: " << source << endl;
    cout << "Target word: " << target << endl;

    while (!finished)
    {
        if (invalid)
        {
            cout << source << " is not a word." << endl;
            invalid = false;
        }

        if (incorrect)
        {
            cout << "Invalid position." << endl;
            incorrect = false;
        }

        cout << "Current word: " << source << ". Enter a command, a position and a letter (all separated by a space): ";
        getline(cin, line);

        string command = "";
        command += line[0];
        command += line[1];
        command += line[2];

        if (command == "swa" && line[3] == 'p')
        {
            pos = line[5] - 48;
            letter = line[7];

            if (pos <= 0 || pos > source.length())
            {
                incorrect = true;
            }

            else
            {
                char old = source[pos - 1];
                source[pos - 1] = letter;

                bool found = false;

                for (int i = 0; i < dictionary.size() && !found; i++)
                {
                    if (source == dictionary.at(i))
                    {
                        found = true;
                    }
                }

                if (!found)
                {
                    invalid = true;
                    source[pos - 1] = old;
                }
            }

            if (source == target)
            {
                cout << "Congrats, you won!" << endl;
                finished = true;
            }
        }

        else if (command == "ins")
        {
            pos = line[4] - 48;
            letter = line[6];

            if (pos >= source.length())
            {
                source += letter;
            }

            else
            {
                if (pos < 1)
                {
                    pos = 1;
                }

                char old = letter;
                char new_c;
                char end = source[source.length() - 1];

                for (int i = pos - 1; i < source.length(); i++)
                {
                    new_c = old;
                    old = source[i];
                    source[i] = new_c;
                }

                source += end;
            } 
        }

        else if (command == "del")
        {
            pos = line[4] - 48;

            if (pos >= source.length() - 1)
            {
                source.erase(source.length() - 1);
            }

            else if (pos <= 0)
            {
                source.erase(0);
            }

            else
            {
                source.erase(source.begin() + pos - 1);
            }
        }

        else
        {
            cout << "Invalid command." << endl;
        }

        if (source == target)
        {
            cout << "Congrats, you won!" << endl;
            finished = true;
        }
    }
}