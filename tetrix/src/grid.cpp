#include "grid.h"

Grid::Grid()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numColumns; column++)
        {
            cells[row][column] = 0;
        }
    }
}

void Grid::gridDraw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numColumns; column++)
        {
            if (cells[row][column] == 0)
            {
                // Draw a filled rectangle for an occupied cell
                DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, black);
            }
            else
            {
                // Draw an outline for an empty cell
                DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, white);
            }
        }
    }
}


void Grid::gridPrint()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numColumns; column++)
        {
            cout << cells[row][column] << " ";
        }
        cout << endl;
    }
}

bool Grid::cellBoundary(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numColumns)
    {
        return false;
    }
    return true;
}

bool Grid::overmoveRight(int row, int column)
{
    if (column < 0)
    {
        return false;
    }
    return true;
}

bool Grid::bottomLock(int row)
{
    return (row == numRows);
}