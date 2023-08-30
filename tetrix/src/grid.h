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
    void gridDraw();
    void gridPrint();

};
