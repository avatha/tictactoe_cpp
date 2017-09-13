#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Board
{
public:
    Board(int size);
    const char X = 'X';
    const char O = 'O';
    vector<char> getGrid();
    void setGrid(vector<char> grid);
    char getSlot(int position);
    void fillSlot(int position);
    long countMarker(char marker);
    char whoseTurn();
    bool isFull();
    vector<int> validSlots();
    bool isEquals(vector<char> board_to_compare);
private:
    int _size;
    vector<char> _grid;
};
