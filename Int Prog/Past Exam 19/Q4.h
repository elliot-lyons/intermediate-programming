#include <vector>
#include <string>
#include <iostream>

using namespace std;

class GameSquare
{
    public:
    GameSquare();

    bool is_empty, is_cross, is_nought;
    char val;

    bool set(char c);
    void show();
};

class Board
{
    public:
    Board();

    vector<vector<GameSquare>> board;

    void show();
    bool has_line(int i);
    bool all_used();
};