#include "AMorse.cpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{

    Morse mrs("morsepairs.txt");
    mrs.display();

    Morse z("z");
    z.display();

    cout << mrs.encode_a_letter('A') << endl;
    cout << mrs.encode_a_letter('a') << endl;
    cout << mrs.encode_a_letter('m') << endl;

    cout << mrs.decode_a_letter("..-.") << endl;
    cout << mrs.decode_a_letter("feh") << endl;

    cout << mrs.encode_a_word("ABBA") << endl;

    cout << mrs.decode_a_word("doesnt matter") << endl;
    
    return 1;
}