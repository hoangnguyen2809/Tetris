#pragma once
#include<raylib.h>
#include<vector>
#include<map>

using namespace std;

const int cellSize = 30;

const Color black = { 0,0,0,255 };
const Color white = { 200,200,200,255 };

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
public:
	int id;
    map<int, vector<Position>> cells;

    Block();

    void blockDraw();
    void Move(int rows, int columns);
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