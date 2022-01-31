#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void fancy_print(vector<string> r);

int main(int argc, char *argv[]) {
    // open indicated file
    // get lines making vectors from rules

    char *fname;
    ifstream file;
    fname = argv[1]; // filename is first command line argument

    file.open(fname);

    string line;
    int nrules = 0;
    vector<string> rule;
    vector<vector<string>> the_rules;
    size_t i, start,len; // len is number of characters in a category
    string category;
    int daughter;
    vector<int> the_daughters;

    while(getline(file,line)) {

        daughter = 0;
	i = line.find(" --> "); // i is first after mother
	start = i + 5;          // start is first of daughter
        len = i;                // length of mother is i
	category = line.substr(0,len); // make string from mother

	rule.push_back(category); // mother of rule gets pushed

	/* push all daughters up to last comma */
	while((i = line.find(",",start)) != string::npos) {
            len = i-start;     // length of current daughter 
	    category = line.substr(start,len);
	    rule.push_back(category);
	    start = i + 1;
	    daughter++;
	}

	/* push last dtr */

	daughter++;
	the_daughters.push_back(daughter);                       // this is storing the number of daughters corresponding to each rule (Exc. 9)
	
	category = line.substr(start);
	rule.push_back(category);
	
	the_rules.push_back(rule);                               // this is storing the entire rule in a vector of rules (Exc. 8)

	nrules++;
        rule.clear();
    }
    cout << "number of rules was " << nrules << endl;

    for (int i = 0; i < the_rules.size(); i++)
      {
	fancy_print(the_rules.at(i));                            // printing out all the rules after they have been stored in a vector (Exc. 8)
      }

    bool quit = false;

    while (!quit)                                                // Exc. 9
      {
	cout << "\nEnter a number (or a word to quit): ";        // This is asking the user to input a number, if they input a string the program will be terminated
	int choice;
	cin >> choice;
	int count = 0;

	if (cin.fail())
	  {
	    quit = true;
	  }

	else
	  {
	    for (int i = 0; i < the_daughters.size(); i++)        // Checking if the number of daughters match the input
	      {
		if (choice == the_daughters.at(i))
		  {
		    fancy_print(the_rules.at(i));                 // If they do, they're printed to the screen
		    count++;
		  }
	      }

	    if (count == 0)
	      {
		cout << "\nThere are no mothers with "  << choice << " daughters.\n";        // If the user inputs a number and there are no rules with said amount of daughters, this message appears
	      }
	  }

	cin.clear();
      }

    return 1;
}

void fancy_print(vector<string> r) {
    cout << r[0];
    cout << " --> " << endl;
    for (unsigned int i = 1; i < r.size(); i++) {
	cout << "     " << r[i] << endl;
    }

}








