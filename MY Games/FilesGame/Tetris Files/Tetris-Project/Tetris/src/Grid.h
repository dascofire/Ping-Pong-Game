#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

// Definition of the Grid class
class Grid {
    public:
        // Constructor for the Grid class
        Grid();

        // Method to initialize the grid with default values
        void Initialize();

        // Method to print the grid to the console
        void PrintGrid();

        // Method to draw the grid on the screen
        void Draw();

        bool IsCellOutside(int Row, int Columns);

        bool IsCellEmpty(int Row, int Columns);

        int ClearFullRows();

        // 2D array representing the grid, with fixed dimensions of 20x10
        int grid[20][10];

    private:

        bool IsRowFull(int row);

        void ClearRow(int row);

        void MoveRowDown(int Row, int NumRows);

        // Number of rows in the grid
        int numRows;

        // Number of columns in the grid
        int numCols;

        // Size of each cell in the grid
        int cellSize;

        // Vector storing the colors for the grid cells
        vector<Color> colors;
};
