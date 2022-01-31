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

    void show();
    bool has_line(char &c);
    bool all_used();
    bool set(int row, int col, char c);
    
    //private:
    vector<vector<GameSquare>> board;
    GameSquare* the_board[3][3];
};