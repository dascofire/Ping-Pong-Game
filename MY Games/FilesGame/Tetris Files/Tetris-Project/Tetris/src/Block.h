#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "Colors.h"

using namespace std;

class Block
{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int row, int columns);
    vector<position> GetCellPosition();
    void Rotate();
    void UndoRotation();
    int id;
    map<int, vector<position>> cells;
private:
    int CellSize;
    int RotatinState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

