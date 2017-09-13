#include "board.hpp"

Board::Board(int size){
    _size = size;
    _grid = vector<char>(size, ' ');
}

vector<char> Board::getGrid(){
    return _grid;
};

void Board::setGrid(vector<char> grid){
    _grid = grid;
};

char Board::getSlot(int position){
    return _grid[position];
};

void Board::fillSlot(int position){
    char marker = whoseTurn();
    _grid[position] = marker;
};

long Board::countMarker(char marker){
    long marker_count = count_if(_grid.begin(),
                                 _grid.end(),
                                 [marker](int c){
                                     return c == marker;
                                 });
    return marker_count;
}

char Board::whoseTurn(){
    if(countMarker(X) > countMarker(O)){
        return O;
    }
    return X;
};

bool Board::isFull(){
    if(countMarker(X) + countMarker(O) == _size){
        return true;
    }
    return false;
}

vector<int> Board::validSlots(){
    vector<int> valid_slots;
    vector<char>::iterator iter;
    
    for(iter = _grid.begin(); iter != _grid.end(); iter++){
        if(*iter == ' '){
            valid_slots.push_back(static_cast<unsigned int>(distance(_grid.begin(), iter)));
        }
    }
    return valid_slots;
}

bool Board::isEquals(vector<char> board_to_compare){
    for (unsigned i = 0; i < _size; i++) {
        if(_grid[i] != board_to_compare[i]) {
            return false;
        }
    }
    return true;
};
