#include "Q3.cpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Board board;
    board.show();

    int row_pos, col_pos;
    char c;
    int test = 0;
    int i = 1;
    string line;
    bool ok = true;
    bool finished = false;

    while(!finished)
    {
        if((i % 2) == 0) 
        {
            c = 'O'; cout << "O player ";
        }

        else 
        {
            c = 'X'; cout << "X player ";
        }

        cout << "Please enter the row and column you wish to enter in(separated by a space): " << endl;
        getline(cin, line);                                                        //(2)read in values for row pos and col pos

       char the_row = line[0];
       char the_col = line[2];

       row_pos = (int) the_row - 48;
       col_pos = (int) the_col - 48;

       cout << col_pos << endl;
       
       if (the_col == '1')
       {
           col_pos = 0;
       }

       else if (the_col == '2')
       {
           col_pos = 1;
       }

       else if (the_col == '3')
       {
           col_pos = 2;
       }

       else
       {
           col_pos = 3;
       }

       row_pos -= 1;


        if(!ok) 
        { 
            cout << "not ok try again\n";
        }

        else 
        {
            board.show();
//(4)if there is a winner report it and break
//(5)if no spaces left report it and break
        }
    i++;
    } // end else
 // end while(true)
    

    return 1;
}