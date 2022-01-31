#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;

wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

vector<vector<int>> erasechars(string& a_line);
void highlight(string& a_line, string the_code);
void restorechars(string& line, vector<vector<int>> deleted);
void display(string clue, string word);
bool is_pal_ascii(string s);
bool is_pal_unicode(string s);

int main()
{
    //display("clue.txt", "beaver");
    
    cout << is_pal_ascii("abba") << endl;
    cout << is_pal_ascii("ABBA") << endl;

    cout << is_pal_ascii("no") << endl;

    cout << is_pal_ascii("civic") << endl;
    cout << is_pal_ascii("cIviC") << endl;

    cout << is_pal_ascii("efKek") << endl;

    cout << is_pal_unicode("été") << endl;
    cout << is_pal_unicode("étré") << endl;
    cout << is_pal_unicode("éétré") << endl;

    return 1;
}

vector <vector <int>> erasechars(string &a_line)
{
   vector<vector<int>> erased;

    for (int i = 0; i < a_line.length(); i++)
    {
        if (a_line[i] == ' ' || a_line[i] == '.')
        {
            vector<int> current;
            
            if (a_line[i] == ' ')
            {
                current.push_back(1);
            }

            else
            {
                current.push_back(0);
            }

            current.push_back(i);

            erased.push_back(current);
            a_line.erase(a_line.begin() + i);
        }
    }

    return erased;
}

void highlight(string& a_line, string the_code)
{
    size_t find = a_line.find(the_code);

    if (find != string::npos)
    {
        for (int i = (int) find; i < ((int) find + the_code.length()); i++)
        {
            a_line[i] -= 32;
        }
    }
}

void restorechars(string& line, vector<vector<int>> deleted)
{
    for (int i = 0; i < deleted.size(); i++)
    {
        vector <int> current = deleted.at(i);
        string insert;
        int index = current.at(1);

        if (current.at(0) == 1)
        {
            insert = " ";
        }

        else
        {
            insert = ".";
        }

       line.insert(index + i, insert);
    }
}

void display(string clue, string word)
{
    vector <string> the_lines;
    ifstream file(clue);

    if (!file)
    {
        cout << "Unable to open file" << endl;
    }

    else
    {
        string line;
        while (getline(file, line))
        {
            the_lines.push_back(line);
        }

        for (int i = 0; i < the_lines.size(); i++)
        {
            string coded_line = the_lines.at(i);

            vector <vector <int>> removed_chars = erasechars(coded_line);

            highlight(coded_line, word);

            restorechars(coded_line, removed_chars);
            cout << coded_line << endl;
        }
    }
}

bool is_pal_ascii(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;         // decapitalising
        }
    }

    // cout << s << endl;

    int mid;

    if (s.length() % 2 == 0)
    {
        mid = s.length() / 2;

        for (int i = 0; i + mid < s.length(); i++)
        {
            if (s[mid - i - 1] != s[mid + i])
            {
                return false;
            }
        }
    }

    else
    {
        mid = (s.length() - 1) / 2;

        for (int i = 0; i < mid; i++)
        {
            if (s[mid - i] != s[mid + i])
            {
                return false;
            }
        }
    }

    return true;
}

bool is_pal_unicode(string s)
{
    cout << s[0] << endl;
    u32string s32 = cvt.from_bytes(s);

    int mid;

    if (s32.length() % 2 == 0)
    {
        mid = s32.length() / 2;

        for (int i = 0; i + mid < s32.length(); i++)
        {
            if (s32[mid - i - 1] != s32[mid + i])
            {
                return false;
            }
        }
    }

    else
    {
        mid = (s32.length() - 1) / 2;

        for (int i = 0; i < mid; i++)
        {
            if (s32[mid - i] != s32[mid + i])
            {
                return false;
            }
        }
    }
    return true;
}