#include "Block.h"


using namespace std;


Block::Block(){
    CellSize = 30;
    RotatinState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY){
    vector<position> tiles = GetCellPosition();
    for (position item: tiles)
    {
        DrawRectangle(item.columns * CellSize + offsetX, item.row * CellSize + offsetY, CellSize - 1, CellSize - 1, colors[id]);
    }
    
}

void Block::Move(int row, int columns){
    rowOffset += row;
    columnOffset += columns;
}

vector<position> Block::GetCellPosition(){
    vector<position> tiles = cells[RotatinState];
    vector<position> movedTiles;
    for(position item : tiles){
        position newPos = position(item.row + rowOffset, item.columns + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate(){
    RotatinState++;
    if (RotatinState == (int)cells.size())
    {
        RotatinState = 0;
    }
    
}

void Block::UndoRotation(){
    RotatinState--;
    if (RotatinState == -1)
    {
        RotatinState = cells.size() - 1;
    }
    
}