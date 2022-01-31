#include <string>
#include <vector>

using namespace std;

class House
{
    public:
    House();
    bool win_state;

    void show();
    void flr_clean();

    private:
    bool flr_state;
};