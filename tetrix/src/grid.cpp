#include "grid.h"



Grid::Grid()
{
    gridInitialize();
}

void Grid::gridInitialize()
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
                int cellValue = cells[row][column];
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

bool Grid::emptyCell(int row, int column)
{
    return (cells[row][column] == 0);
}

int Grid::clearFullRows()
{
    int fullRows = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (fullRow(row))
        {
            clearRow(row);
            fullRows++;
        }
        else if (fullRows > 0)
        {
            moveRowDown(row, fullRows);
        }
    }
    return fullRows;
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

bool Grid::fullRow(int row)
{
    for (int column = 0; column < numColumns; column++)
    {
        if (cells[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row)
{
    for (int col = 0; col < numColumns; col++)
    {
        cells[row][col] = 0;
    }
}

void Grid::moveRowDown(int row, int numRows)
{
    for (int col = 0; col < numColumns; col++)
    {
        cells[row + numRows][col] = cells[row][col];
        cells[row][col] = 0;
    }
}

