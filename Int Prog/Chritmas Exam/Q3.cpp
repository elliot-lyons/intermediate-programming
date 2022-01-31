#include "Q3.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

GameSquare::GameSquare()
{
    is_empty = true;
    is_cross = false;
    is_nought = false;

    cout << is_empty << is_cross << is_nought << endl;
}

// GameSquare::GameSquare(int x, int y)
// {
//     is_empty = true;
//     is_cross = false;
//     is_nought = false;
// }

Board::Board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            GameSquare current;
            the_board[i][j] = &current;
        }
    }
}

bool Board::set(int row, int col, char c)
{
    if (row < 3 && col < 3)
    {
        GameSquare* current = the_board[row][col];
        bool result = current->set(c);
        cout << "Inner : " << current->is_cross << "/n";
        GameSquare x = *current;
        cout << x.is_cross << endl;

        return result;

    }
}

bool GameSquare::set(char c)
{
    if (is_empty)
    {
        val = c;

        cout << val << endl;
        cout << c << endl;

        if (val == 'X')
        {
            is_empty = false;
            is_cross = true;
            is_nought = false;
            return true;
        }

        else if (val == 'O')
        {
            is_empty = false;
            is_nought = true;
            is_cross = true;
            return true;
        }

        else 
        {
            return false;
        }
    }

    return false;
}

bool Board::all_used()
{
    for (int i = 0; i < board.size(); i++)
    {
        vector<GameSquare> line = board.at(i);

        for (int j = 0; j < line.size(); j++)
        {
            GameSquare current = line.at(i);

            if (!current.is_empty)
            {
                return true;
            }
        }
    }

    return false;
}

void GameSquare::show()
{
    // if (is_empty)
    // {
        // cout << " ";
    // }

    if (is_nought)
    {
        cout << "nought";
    }

    if (is_cross)
    {
        cout << "cross";
    }
}

void Board::show()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "-------" << endl;
        cout << "|";

        for (int j = 0; j < 3; j++)
        {
            GameSquare* gs = the_board[i][j];
            
            // if (gs.is_cross)
            // {
            //     cout << "cross" << endl;
            // }

            // else if(gs.is_nought)
            // {
            //     cout << "0" << endl;
            // }

            // else if (gs.is_empty)
            // {
            //     cout << "emp" << endl;
            // }

            // else
            // {
            //     cout << "fail" << endl;
            // }

            //cout << gs->is_cross << endl;

            //gs->show();

            GameSquare x = *gs;
            //cout << x.is_cross << endl;
            x.show();
            cout << "|";
        }

        cout << endl;
    }

    cout << "-------" << endl;
}

// bool Board::has_line(int i)
// {
//     return (i == 1);
// }