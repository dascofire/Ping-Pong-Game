#include "Game.h"
#include <random>

using namespace std;

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    GameOver = false;
    score = 0;
}

Block Game::GetRandomBlock(){
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    
    int RandomIndex = rand() % blocks.size();
    Block block = blocks[RandomIndex]; 
    blocks.erase(blocks.begin() + RandomIndex);
    return block;
}

vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), ZBlock(), TBlock(), OBlock(), SBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw(11, 11);
    switch (NextBlock.id)
    {
    case 3:
        NextBlock.Draw(255, 290);
        break;
    case 4:
        NextBlock.Draw(255, 280);
        break;
    default:
        NextBlock.Draw(270, 270);
        break;
    }
}

void Game::HandleInput(){
    int KeyPressed = GetKeyPressed();
    if (GameOver && KeyPressed != 0){
        GameOver = false;
        Reset();
    }
    switch (KeyPressed)
    {
    case KEY_LEFT:
    MoveBlockLeft();
        break;
    case KEY_RIGHT:
    MoveBlockRight();
        break;
    case KEY_DOWN:
    MoveBlockDown();
    UpdateScore(0, 1);
        break;
    case KEY_UP:
    BlockRotate();
        break;
    }
}

void Game::MoveBlockLeft(){
    if (!GameOver )
    {
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlocksFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }        
}

void Game::MoveBlockRight(){
    if (!GameOver) {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlocksFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown(){
    if (!GameOver){
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlocksFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

bool Game::IsBlockOutside(){
    vector<position> tiles = currentBlock.GetCellPosition();
    for (position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.columns))
        {
            return true;
        }
    }
    return false;
}

void Game::BlockRotate(){
    if (!GameOver){
        currentBlock.Rotate();
        if (IsBlockOutside() || BlocksFits() == false)
        {
            currentBlock.UndoRotation();
        }
    }
}

void Game::LockBlock(){
    vector<position> tiles = currentBlock.GetCellPosition();
    for(position item : tiles){
        grid.grid[item.row][item.columns] = currentBlock.id;
    }
    currentBlock = NextBlock;
    if (BlocksFits() == false)
    {
        GameOver = true;
    }
    
    NextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

bool Game::BlocksFits(){
    vector<position> tiles = currentBlock.GetCellPosition();
    for(position item : tiles){
        if (grid.IsCellEmpty(item.row , item.columns) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset(){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int LinesCleared, int moveDown){
    switch (LinesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    
    default:
        break;
    }
    score += moveDown;
}