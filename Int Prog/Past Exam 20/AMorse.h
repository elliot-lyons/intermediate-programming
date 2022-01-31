#include <string>
#include <vector>
using namespace std;

struct CodePair
{
    char plain;
    string code;
};

class Morse
{
    public:
        Morse(string fname);
        Morse();
        string encode_a_letter(char c);
        char decode_a_letter(string x);
        string encode_a_word(string w);
        string decode_a_word(string w);

        void display();

    private:
        vector<CodePair> code_table;
};