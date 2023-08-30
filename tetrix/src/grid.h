#pragma once
#include<raylib.h>
#include "blocks.h"
#include<iostream>


class Grid
{
private:
    static const int numRows = 20; // Number of rows
    static const int numColumns = 10; // Number of columns


public:
    int cells[numRows][numColumns];
    Grid();

    bool cellBoundary(int row, int column);
    bool overmoveRight(int row, int column);
    bool bottomLock(int row);
    void gridDraw();
    void gridPrint();

};
