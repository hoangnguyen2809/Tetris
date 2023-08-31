#pragma once
#include<raylib.h>
#include<vector>
#include<map>
#include"colors.h"

using namespace std;

const int cellSize = 30;

class Position
{
public:
	Position(int row, int column);
	int row;
	int column;
};

class Block
{
private:
	int rotationState;
    int rowOffset;
    int columnOffset;
    vector<Color> colors;
public:
	int id;
    int colorId;
    map<int, vector<Position>> cells;

    Block();

    void blockDraw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void undoRotation();
    vector<Position> getCellPositions();
};


class LBlock : public Block
{
public:
    LBlock();
};

class JBlock : public Block
{
public:
    JBlock();
};

class IBlock : public Block
{
public:
    IBlock();
};

class OBlock : public Block
{
public:
    OBlock();
};

class SBlock : public Block
{
public:
    SBlock();
};

class TBlock : public Block
{
public:
    TBlock();
};

class ZBlock : public Block
{
public:
    ZBlock();
};