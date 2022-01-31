#include "Q4.cpp"
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

    while (!board.all_used() || !board.has_line(test))
    {
        if ((i % 2) == 0)
        {
            c = 'O';
            cout << "O player:" << endl;
        }
        else
        {
            c = 'X';
            cout << "X player: " << endl;
        }

        cout << "Please enter the row and column you wish to enter in: " << endl;
        cin >> line;

        char the_row = line[0];
        char the_col = line[2];

        row_pos = (int) the_row - 48;
        col_pos = (int) the_col - 48;

        for (int i = 0; i < row_pos; i++)
        {
            vector <GameSquare> current = board.board.at(i);
            
            for (int j = 0; j < col_pos; j++)
            {
                GameSquare gs = current.at(j);
                bool x = gs.set(c);
                cout << x << endl;
            }
        }

        board.show();
        i++;
    }
    

    return 1;
}