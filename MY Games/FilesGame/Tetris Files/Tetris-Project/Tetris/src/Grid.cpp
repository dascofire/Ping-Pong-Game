#include "Grid.h"
#include <iostream>
#include "Colors.h"

using namespace std;

// Constructor for the Grid class
Grid::Grid(){
    numRows = 20;  // Set the number of rows in the grid
    numCols = 10;  // Set the number of columns in the grid
    cellSize = 30; // Set the size of each cell in the grid
    Initialize();  // Initialize the grid with default values
    colors = GetCellColors(); // Get the color palette for the grid cells
}

// Initialize the grid with default values (all cells set to 0)
void Grid::Initialize(){
    for (int row = 0; row < numRows ; row++) {
        for (int colomus = 0; colomus < numCols; colomus++) {
            grid[row][colomus] = 0; // Set each cell in the grid to 0
        }
    }
}

// Print the grid to the console
void Grid::PrintGrid(){
    for (int row = 0; row < numRows; row++) {
        for (int columns = 0; columns < numCols; columns++) {
            cout << grid[row][columns] << " "; // Print the value of each cell
        }
        cout << std::endl; // Move to the next line after each row
    }
}

// Draw the grid on the screen
void Grid::Draw(){
    for (int row = 0; row < numRows; row++) {
        for (int columns = 0; columns < numCols; columns++) {
            int CellValue = grid[row][columns]; // Get the value of the current cell
            // Draw the rectangle representing the cell on the screen
            // The color of the cell is determined by its value
            DrawRectangle(columns * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[CellValue]);
        }
    }
}

bool Grid::IsCellOutside(int Row, int Columns){
    if (Row >= 0 && Row < numRows && Columns >= 0 && Columns < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int Row, int Columns){
    if (grid[Row][Columns] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows(){
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row){
    for (int columns = 0; columns < numCols; columns++)
    {
        if (grid[row][columns] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row){
    for (int columns = 0; columns < numCols; columns++)
    {
        grid[row][columns] = 0;
    }
    
}

void Grid::MoveRowDown(int Row, int NumRows){
    for (int columns = 0; columns < numCols; columns++)
    {
        grid[Row + NumRows][columns] = grid[Row][columns];
        grid[Row][columns] = 0;
    }
    
}