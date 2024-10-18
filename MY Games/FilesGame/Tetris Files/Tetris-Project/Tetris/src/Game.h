#pragma once
#include "Grid.h"
#include "blocks.cpp"

using namespace std;

class Game {
    public:
        Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool GameOver;
        int score; 

    private:
        vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        bool IsBlockOutside();
        void BlockRotate();
        void LockBlock();
        void Reset();
        void MoveBlockLeft();
        void MoveBlockRight();
        void UpdateScore(int LinesCleared, int moveDown);
        Grid grid;
        bool BlocksFits();
        vector<Block> blocks;
        Block NextBlock;
        Block currentBlock;
};