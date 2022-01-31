#include "Q4.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

GameSquare::GameSquare()
{
    is_empty = true;
    is_cross = false;
    is_nought = false;
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
        vector<GameSquare> line;

        for (int j = 0; j < 3; j++)
        {
            GameSquare current;
            line.push_back(current);
        }

        board.push_back(line);
    }
}

bool GameSquare::set(char c)
{
    if (!is_empty)
    {
        val = c;

        if (val == 'X' || val == 'x')
        {
            is_empty = false;
            is_cross = true;
        }

        else if (val == 'O' || val == 'o')
        {
            is_empty = false;
            is_nought = true;
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
    if (is_empty)
    {
        cout << " ";
    }

    else if (is_nought)
    {
        cout << "O";
    }

    else if (is_cross)
    {
        cout << "X";
    }
}

void Board::show()
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << "-------" << endl;
        cout << "|";
        vector<GameSquare> line = board.at(i);

        for (int j = 0; j < line.size(); j++)
        {
            GameSquare gs = line.at(i);
            gs.show();
            cout << "|";
        }

        cout << endl;
    }

    cout << "-------" << endl;
}

bool Board::has_line(int i)
{
    return (i == 1);
}