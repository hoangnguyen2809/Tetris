#pragma once
#include<raylib.h>
#include "blocks.h"
#include<iostream>


class Grid
{
private:
    static const int numRows = 20; // Number of rows
    static const int numColumns = 10; // Number of columns
    bool fullRow(int row);
    void clearRow(int row);
    void moveRowDown(int row, int numRows);

public:
    int cells[numRows][numColumns];
    Grid();

    void gridInitialize();

    bool cellBoundary(int row, int column);
    bool overmoveRight(int row, int column);
    bool bottomLock(int row);
    void gridDraw();
    void gridPrint();
    bool emptyCell(int row, int column);
    int clearFullRows();

};
